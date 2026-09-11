Morris 遍历的核心目的只有一个：**将二叉树遍历的空间复杂度降为 $O(1)$**。

常规的递归或辅助栈遍历，空间复杂度都是 $O(h)$（$h$ 为树高）。Morris 遍历不借用任何外部数据结构，而是**利用叶子节点大量闲置的 `right` 空指针搭一座“回程桥”**，遍历完了再顺手拆掉，做到不破坏原树结构。

---

**核心骨架：找“前驱节点”搭桥与拆桥**

在**中序遍历**规则下，节点 `curr` 的前一个被访问的节点，一定是**它左子树里最靠右的节点**（称为 `curr` 的**前驱节点**，predecessor）。

```cpp
// 找前驱节点的标准动作
TreeNode* prev = curr->left;
// 一直往右走，但不能走到已经搭好的桥（指向 curr）上
while (prev->right != nullptr && prev->right != curr) {
    prev = prev->right;
}

```

* **如果 `prev->right == nullptr**`：说明这是我们**第一次**来到 `curr`。此时立刻搭桥：`prev->right = curr`，然后放心去探访左子树 `curr = curr->left`。
* **如果 `prev->right == curr**`：说明左子树已经全遍历完了，顺着搭好的桥回到了 `curr`（**第二次**来到 `curr`）。此时立刻拆桥恢复树结构：`prev->right = nullptr`，然后走向右子树 `curr = curr->right`。

---

**模块一：中序遍历（最经典的 Morris）**

在中序遍历中，我们希望遵循“左 -> 根 -> 右”。所以节点的打印必须放在**左子树完全处理完、第二次回访自身**的时候。

```cpp
void morrisInorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        // 分支 1：左边没路了，当前节点本身就是起点，直接访问并转向右子树
        if (curr->left == nullptr) {
            cout << curr->val << " "; // 访问节点
            curr = curr->right;
        } 
        // 分支 2：左边有子树，需要利用前驱节点搭桥
        else {
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // 情况 A：第一次访问 curr，搭桥并走向左子树
            if (prev->right == nullptr) {
                prev->right = curr;       // 搭桥：前驱节点的右指针指向 curr
                curr = curr->left;        // 深入左子树
            } 
            // 情况 B：第二次访问 curr，说明左子树全看完了
            else {
                prev->right = nullptr;    // 拆桥：还原二叉树原始结构
                cout << curr->val << " "; // 中序输出：此时才轮到输出根节点
                curr = curr->right;       // 转向右子树
            }
        }
    }
}

```

---

**模块二：前序遍历（只改一行输出位置）**

前序遍历要求“根 -> 左 -> 右”，即**一旦第一次见到该节点，必须立刻访问它**。
代码与中序遍历完全一致，**仅仅改变访问语句的时机**：

```cpp
void morrisPreorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->val << " "; // 访问节点
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // 情况 A：第一次来到 curr
            if (prev->right == nullptr) {
                cout << curr->val << " "; // 前序输出：第一次碰面就立刻访问！
                prev->right = curr;       // 搭桥
                curr = curr->left;
            } 
            // 情况 B：第二次顺着桥回到 curr
            else {
                prev->right = nullptr;    // 拆桥
                curr = curr->right;       // 此时无需访问 curr，直接去右边
            }
        }
    }
}

```

---

**复杂度与特点分析**

* **空间复杂度 $O(1)$**：仅使用了 `curr` 和 `prev` 两个指针变量，真正实现常数空间。
* **时间复杂度严格 $O(n)$**：虽然看起来有 `while` 套 `while` 找前驱，但每条树边在寻找前驱、搭桥、拆桥的过程中最多只被遍历 2 次，总平摊步数不超过 $3n$ 步。
* **非线程安全**：在遍历过程中，原树的拓扑结构被指针临时修改过，多线程同时只读访问可能会引发死锁或死循环，拆桥完成后树结构完全恢复。

---


后序遍历要求：**“左 -> 右 -> 根”**。

在前序和中序中，我们只要在第一次或第二次到达一个节点时打印它就行。但后序遍历最麻烦的地方在于：**“根节点”必须在它的“右子树”全部遍历完之后才能打印**。

Morris 后序遍历的核心思路非常巧妙：**倒着打印右边界**。

---

**核心技巧：逆序打印单链表**

如果有一串只通过 `right` 指针相连的节点（就像单链表一样）：

```text
A -> B -> C

```

如果我们想按 `C -> B -> A` 的顺序打印，但在 $O(1)$ 空间限制下不能用数组或栈存下来反转，该怎么做？
**答案：就像反转单链表一样，先把它就地反转成 `C -> B -> A`，顺序打印，再反转回去复原。**

---

**后序 Morris 的规则**

在经典 Morris 骨架中：

* 第一次到达 `curr`：搭桥（`prev->right = curr`），往左走。
* **第二次回到 `curr`（即触发 `prev->right == curr`，准备拆桥时）**：
* 这说明：**`curr->left` 这棵子树（它的左边和右边）已经彻底遍历完了！**
* 此时，从 `curr->left` 一直到它的最右节点 `prev` 这条右边缘路径，恰好是后序遍历需要输出的序列的**反向顺序**。
* 动作：**逆序打印从 `curr->left` 到 `prev` 的这一整条右边界**，然后拆桥。


* **整棵树跑完后**：
* 补刀一次：逆序打印从整棵树的 `root` 到它最右节点的这条右边界。



---

**极简代码拆解**

**1. 辅助动作：反转右边缘并逆序打印**

```cpp
// 经典的翻转链表，空间复杂度 O(1)
TreeNode* reverseList(TreeNode* head) {
    TreeNode* pre = nullptr;
    TreeNode* cur = head;
    while (cur != nullptr) {
        TreeNode* next = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// 逆序打印从 from 到 to 的右子树边缘
void printRightEdge(TreeNode* from) {
    TreeNode* tail = reverseList(from); // 1. 先反转
    TreeNode* cur = tail;
    while (cur != nullptr) {
        cout << cur->val << " ";        // 2. 依次打印
        cur = cur->right;
    }
    reverseList(tail);                  // 3. 再次反转恢复原状
}

```

---

**2. 主干逻辑（与中序遍历完全相同，只改了触发动作）**

```cpp
void morrisPostorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // 没有左子树，直接去右子树
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;       // 搭桥
                curr = curr->left;
            } else {
                prev->right = nullptr;    // 拆桥
                
                // 核心改动：第二次回到 curr 时，逆序打印左子树的右边界！
                printRightEdge(curr->left); 
                
                curr = curr->right;
            }
        }
    }

    // 收尾：整棵树遍历完了，最后逆序打印一次整个根节点的右边界
    printRightEdge(root);
}

```

---

**一个直观的小例子**

假设有这棵树：

```text
       4
     /   \
    2     5
   / \
  1   3

```

后序遍历目标结果：`1, 3, 2, 5, 4`

1. 当回到 `2` 准备拆桥时：
* `curr = 2`，此时 `curr->left` 是 `1`，`1` 没有右孩子。
* 逆序打印 `1` 的右边缘：输出 **`1`**。


2. 当回到 `4` 准备拆桥时：
* `curr = 4`，此时 `curr->left` 是 `2`。
* 从 `2` 往右看，这条右边缘是 `2 -> 3`。
* 逆序打印它（反向输出）：输出 **`3, 2`**。


3. 退出 `while` 循环后（收尾）：
* 整棵树的 `root = 4`，从 `4` 往右看，这条右边缘是 `4 -> 5`。
* 逆序打印它：输出 **`5, 4`**。


4. 拼接输出：`1` + `3, 2` + `5, 4` = **`1, 3, 2, 5, 4`**。

通过利用反转链表代替栈，依然保持了严格的 **$O(1)$ 辅助空间** 和 **$O(n)$ 时间**。