## 二叉树的序列化与反序列化

普通二叉树无法仅凭单一遍历顺序还原，但如果在遍历过程中保留空节点占位符（如 `#`）并使用定界符（如逗号 `,`），前序和层序均可实现单序列唯一还原。

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

```

---

### 前序序列化与反序列化 (DFS)

* **核心机制**：序列化时遇到 `nullptr` 输出 `#,`；反序列化时按前序先建根节点，再递归生成左子树与右子树。

```cpp
#include <string>
#include <sstream>
#include <queue>

class CodecPreorder {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) return "#,";
        return std::to_string(root->val) + "," + 
               serialize(root->left) + 
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        std::string item;
        std::queue<std::string> nodes;
        while (getline(ss, item, ',')) {
            if (!item.empty()) nodes.push(item);
        }
        return build(nodes);
    }

private:
    TreeNode* build(std::queue<std::string>& nodes) {
        if (nodes.empty()) return nullptr;
        std::string val = nodes.front();
        nodes.pop();
        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(std::stoi(val));
        root->left = build(nodes);
        root->right = build(nodes);
        return root;
    }
};

```

---

### 层序序列化与反序列化 (BFS)

* **核心机制**：利用标准队列。序列化时空节点同样入队输出 `#,`；反序列化时按父节点顺序依次绑定左、右两个子节点。

```cpp
class CodecLevelOrder {
public:
    std::string serialize(TreeNode* root) {
        if (!root) return "";
        std::string res;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur) {
                res += std::to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                res += "#,";
            }
        }
        return res;
    }

    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;
        std::stringstream ss(data);
        std::string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(std::stoi(item));
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // 处理左子节点
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    parent->left = new TreeNode(std::stoi(item));
                    q.push(parent->left);
                }
            }
            // 处理右子节点
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    parent->right = new TreeNode(std::stoi(item));
                    q.push(parent->right);
                }
            }
        }
        return root;
    }
};

```

---

## 二叉搜索树 (BST) 核心性质与操作

**核心性质**：对任意节点 $X$，其左子树所有节点值 $< X->val <$ 其右子树所有节点值。**中序遍历严格单调递增**。

### 增删改查实现

| 操作 | 核心逻辑 | 平均时间复杂度 | 最坏时间复杂度 |
| --- | --- | --- | --- |
| **查 (Search)** | 目标值与当前节点比大小，小于往左，大于往右 | $O(\log n)$ | $O(n)$ |
| **增 (Insert)** | 寻找到空位置（`nullptr`）挂载新节点 | $O(\log n)$ | $O(n)$ |
| **改 (Update)** | 严禁直接原地修改 `val`（会破坏有序性），需先 `Delete(old)` 再 `Insert(new)` | $O(\log n)$ | $O(n)$ |
| **删 (Delete)** | 区分三种子节点情况（0 个、1 个、2 个） | $O(\log n)$ | $O(n)$ |

```cpp
class BST {
public:
    // 查找
    TreeNode* search(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        return val < root->val ? search(root->left, val) : search(root->right, val);
    }

    // 插入
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else if (val > root->val) {
            root->right = insert(root->right, val);
        }
        return root;
    }

    // 删除（重点：双子节点找右子树最小值/前驱/后继替代）
    TreeNode* remove(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (val < root->val) {
            root->left = remove(root->left, val);
        } else if (val > root->val) {
            root->right = remove(root->right, val);
        } else {
            // 情况 1 & 2: 只有 0 或 1 个子节点
            if (!root->left) {
                TreeNode* r = root->right;
                delete root;
                return r;
            }
            if (!root->right) {
                TreeNode* l = root->left;
                delete root;
                return l;
            }
            // 情况 3: 拥有双子节点，寻找右子树的最小值（后继节点）
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = remove(root->right, minNode->val);
        }
        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};

```
判断一棵二叉树是否为有效二叉搜索树（BST），核心在于**整棵子树的约束传递**，而不仅是局部满足 `left->val < root->val < right->val`。

常见经典解法有三种：**中序遍历单调性检查**、**前序区间递归约束**以及 **$O(1)$ 额外空间的 Morris 遍历**。

---

### 方法一：中序遍历（最直观、易写）

* **原理**：BST 的充要条件是**中序遍历序列严格单调递增**（无重复节点时）。遍历过程中只需记录前驱节点的值 `prev`，一旦当前节点值 $\le$ `prev`，即可判定不是 BST。
* **时空复杂度**：时间 $O(n)$，空间 $O(h)$（递归调用栈深度）。

```cpp
class Solution {
private:
    long long prev = LLONG_MIN; // 用 long long 防止节点值为 INT_MIN 时误判

public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        // 1. 递归检查左子树
        if (!isValidBST(root->left)) return false;

        // 2. 检查当前节点是否严格大于前驱
        if (root->val <= prev) return false;
        prev = root->val;

        // 3. 递归检查右子树
        return isValidBST(root->right);
    }
};

```

> **常见易错点**：使用全局变量或类成员变量时，如果连续调用或存在多组数据，记得重置 `prev`；或者通过传递指针/引用 `long long* prev` 避免污染。

---

### 方法二：带上下界的递归遍历（前序约束传递）

* **原理**：自顶向下传递每个节点必须满足的开区间范围 $(\text{lower}, \text{upper})$：
* 进入左子树时，上界收缩为当前节点值：$(\text{lower}, \text{root->val})$。
* 进入右子树时，下界收缩为当前节点值：$(\text{root->val}, \text{upper})$。


* **避坑关键**：避免仅比较父子节点。例如下面这棵树，局部均满足，但全局节点 `3` 出现在根节点 `5` 的右子树中，不是有效 BST：
```text
      5
     / \
    4    6
        / \
      [3]  7   <-- 错误！3 处于 5 的右侧，违反了整棵右子树 > 5 的全局约束

```


* **代码实现**：

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

private:
    // 传指针表示上下界，避免 INT_MIN / INT_MAX 的溢出边界特判
    bool validate(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (!node) return true;

        if (low && node->val <= low->val) return false;
        if (high && node->val >= high->val) return false;

        return validate(node->left, low, node) && 
               validate(node->right, node, high);
    }
};

```

---

### 方法三：Morris 中序遍历（$O(1)$ 辅助空间优化）

* **原理**：利用二叉树中大量叶子节点的空指针（`right = nullptr`）建立指向中序后继的临时线索（Threaded Binary Tree），在回溯时恢复树的原结构，在整个遍历流程中依然检查值是否单调递增。
* **时空复杂度**：时间 $O(n)$，额外空间复杂度 $O(1)$。

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* prevNode = nullptr;
        bool isValid = true;

        while (cur) {
            if (!cur->left) {
                // 访问当前节点
                if (prevNode && cur->val <= prevNode->val) {
                    isValid = false; // 标记失效，但不立即 return，需走完以复原树结构
                }
                prevNode = cur;
                cur = cur->right;
            } else {
                // 找前驱节点（左子树的最右节点）
                TreeNode* pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    // 建立临时线索
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    // 线索已存在，说明左子树遍历完毕，拆除线索并访问当前节点
                    pre->right = nullptr;
                    if (prevNode && cur->val <= prevNode->val) {
                        isValid = false;
                    }
                    prevNode = cur;
                    cur = cur->right;
                }
            }
        }
        return isValid;
    }
};

```

---

### 三种方法横向对比

| 方法 | 核心思路 | 优点 | 缺点 / 注意事项 |
| --- | --- | --- | --- |
| **中序遍历递归** | 检查中序输出是否单调严格递增 | 代码最直观，符合 BST 本质 | 递归消耗栈空间，注意初值边界 |
| **区间上下界传递** | 自顶向下递归约束 $(\text{low}, \text{high})$ | 可以在访问到非法节点的第一时间立刻剪枝返回 | 需处理极值溢出（建议用指针传参） |
| **Morris 遍历** | 动态线索二叉树 | **$O(1)$ 额外空间**，无栈开销 | 会临时修改树结构，发现非法后必须遍历完以还原指针 |