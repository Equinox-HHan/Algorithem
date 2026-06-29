# 数据结构

## 栈：先进后出

[!tips] 栈是线性表但是底层物理内存不一定连续
>内存管理的系统栈：严格连续
>STL中的栈：默认不连续但可以手动改为连续

1. 声明：stack<TYPE> _name_
2. 操作：
—————————————————————————————————————————————
|push(_val_) |压入val                       | 
|top()       |返回栈顶的数据                |
|pop()       |弹出栈顶的元素（无返回值）    |
|empty()     |检查是否为空（返回布尔值）    |
|size()      |获取栈中元素个数（）          |
—————————————————————————————————————————————


## 向量：动态数组

1. 声明：
——————————————————————————————————————————————————————————————————————————
|vector<TYPE> _name_             |产生一个空的向量                      |
|vector<TYPE> _name1_(_name2_)   |产生一个name2的副本                   |
|vector<TYPE> _name_(n)          |产生一个大小为n的向量                 |
|vector<TYPE> _name_(n,element)  |产生大小为n的向量，每个元素都是element|
|_name_.vector<TYPE>()           |销毁所有元素并且释放内存              |
——————————————————————————————————————————————————————————————————————————
2. 操作：
——————————————————————————————————————————————————————————————————————————————
|c.assign(beg, end)        |将 [beg, end) 区间的数据赋值给 c                 |
|c.assign(n, elem)         |将 n 个 elem 的复制赋值给 c                      |
|c.back()                  |传回最后一个数据，不检查这个数据是否存在         |
|c.begin()                 |传回迭代器中的第一个数据地址                     |
|c.end()                   |指向迭代器中的最后一个数据地址                   |
|c.capacity()              |当前已经分配的可以容纳的元素个数                 |
|c.size()                  |返回容器中实际数据的个数                         |
|c.clear()                 |移除容器中的所有数据                             |
|c.empty()                 |判断容器是否为空                                 |
|c.erase(pos)              |删除 pos 位置的数据，传回下一个数据的位置        |
|c.erase(beg, end)         |删除 [beg, end) 区间的数据，传回下一个数据的位置 |
|c.insert(pos, elem)       |在 pos 位置插入一个 elem 的副本，传回新数据位置  |
|c.insert(pos, n, elem)    |在 pos 位置插入 n 个 elem 数据。无返回值         |
|c.insert(pos, beg, end)   |在 pos 位置插入 [beg, end) 区间的数据。无返回值  |
|c.pop_back()              |删除最后一个数据                                 |
|c.push_back(elem)         |在尾部加入一个数据 elem                          |
|c.swap(c2)                |将 c1 和 c2 元素互换                             |
|swap(c1, c2)              |将 c1 和 c2 元素互换                             |
——————————————————————————————————————————————————————————————————————————————


## 映射：键值对

### map：有序映射
**底层的数据结构是红黑树（有序+稳定）**

- 默认情况下按照key升序从小到大组织元素
- key的数据类型必须支持<运算符，否则要进行运算符重载
- 除非手动删除某个节点，否则迭代器不会失效
- 增删查改时间复杂度均为树的高度O(logN)

标准声明：map<KEY, VALUE, Compare> _name_

### unordered_map：无序映射
**底层的数据结构是哈希表和桶数组（快速）**

- key的类型必须支持==运算并且要有对应的哈希函数
- 可能会扩容，扩容时所有迭代器失效
- 增删改查平均复杂度O(1),最坏情况下O(N)

标准声明：unordered_map<KEY, VALUE, Hash, Pred> _name_

——————————————————————————————————————————————————————————————————————————————————————
|m[key] = value            |插入或修改：通过下标访问，若 key 不存在则直接创建        |
|m.insert(pair)            |插入：传入一个 std::pair，若 key 已存在则插入失败        |
|m.erase(key)              |删除：根据键 key 删除对应的键值对                        |
|m.find(key)               |查找：返回指向该 key 的迭代器，若没找到则返回 m.end()    |
|m.count(key)              |计数：返回 key 出现的次数（由于 key 唯一，只能是 0 或 1）|
|m.size()                  |大小：返回当前映射中键值对的个数                         |
|m.clear()                 |清空：移除映射中的所有元素                               |
——————————————————————————————————————————————————————————————————————————————————————


## 链表

### list：双向列表
**节点包含数据和前后指针，节点在内存散存放**

1. 声明：
————————————————————————————————————————————————————————————————————————————————————
|std::list<TYPE> _name_                 |产生一个空的双向列表                      |
|std::list<TYPE> _name1_(_name2_)       |产生一个 name2 的副本（深拷贝）           |
|std::list<TYPE> _name_(n)              |产生一个大小为 n 的列表，元素默认初始化   |
|std::list<TYPE> _name_(n, element)     |产生大小为 n 的列表，每个元素都是 element |
|std::list<TYPE> _name_ = {e1, e2, ...} |使用初始化列表赋初值（C++11）             |
————————————————————————————————————————————————————————————————————————————————————
2. 操作：
——————————————————————————————————————————————————————————————————————————————
|c.push_front(elem)        |在头部插入一个数据 elem                          |
|c.pop_front()             |删除头部第一个数据                               |
|c.push_back(elem)         |在尾部加入一个数据 elem                          |
|c.pop_back()              |删除最后一个数据                                 |
|c.front()                 |返回第一个元素的引用                             |
|c.back()                  |返回最后一个元素的引用                           |
|c.begin()                 |传回指向第一个节点的双向迭代器                   |
|c.end()                   |指向最后一个节点后面（哨兵位）的双向迭代器       |
|c.insert(pos, elem)       |在迭代器 pos 位置前插入 elem，返回新数据位置     |
|c.erase(pos)              |删除迭代器 pos 位置的数据，返回下一个数据的位置  |
|c.remove(val)             |直接删除链表中所有值等于 val 的节点（按值删除）  |
|c.unique()                |移除连续重复的元素（只保留一个）                 |
|c.sort()                  |排序：必须用自带的成员函数排序（底层归并排序）   |
|c.reverse()               |反转链表                                         |
|c.size()                  |返回容器中实际数据的个数                         |
|c.clear()                 |移除容器中的所有数据                             |
——————————————————————————————————————————————————————————————————————————————

### forward_list:单向列表
**指针只向后指不能向前寻找**

1. 声明：
————————————————————————————————————————————————————————————————————————————————————————
|std::forward_list<TYPE> _name_             |产生一个空的单向列表                     |
|std::forward_list<TYPE> _name1_(_name2_)   |产生一个 name2 的副本                    |
|std::forward_list<TYPE> _name_(n)          |产生一个大小为 n 的单向列表              |
|std::forward_list<TYPE> _name_(n, element) |产生大小为 n 的单向列表，元素均为 element|
|std::forward_list<TYPE> _name_ = {e1, ...} |使用初始化列表赋初值                     |
————————————————————————————————————————————————————————————————————————————————————————
2. 操作：
———————————————————————————————————————————————————————————————————————————————
|c.push_front(elem)        |在头部插入一个数据 elem                          |
|c.pop_front()             |删除头部第一个数据                               |
|c.front()                 |返回第一个元素的引用（没有 c.back()）            |
|c.before_begin()          |返回指向第一个节点前面那个虚拟位置的迭代器       |
|c.begin()                 |传回指向第一个节点的单向迭代器                   |
|c.end()                   |指向最后一个节点后面的单向迭代器                 |
|c.insert_after(pos, elem) |在迭代器 pos 之后插入 elem，返回新数据位置       |
|c.erase_after(pos)        |删除迭代器 pos 之后的数据，返回下一个数据的位置  |
|c.remove(val)             |直接删除链表中所有值等于 val 的节点              |
|c.unique()                |移除连续重复的元素                               |
|c.sort()                  |排序：必须用自带的成员函数排序                   |
|c.reverse()               |反转链表                                         |
|c.clear()                 |移除容器中的所有数据                             |
——————————————————————————————————————————————————————————————————————————————


## 队列：先进先出

### queue：传统队列
———————————————————————————————————————————————————————————————————————————
|std::queue<TYPE> _name_   |声明一个空的标准队列                          |
|q.push(elem)              |入队：在队尾插入一个数据 elem                 |
|q.pop()                   |出队：删除队头第一个数据，不返回值            |
|q.front()                 |返回队头第一个元素的引用（最先辈的数据）      |
|q.back()                  |返回队尾最后一个元素的引用（刚排进来的数据    |
|q.size()                  |返回队列中元素的个数                          |
|q.empty()                 |判断队列是否为空                              |
———————————————————————————————————————————————————————————————————————————

### deque：双端队列
——————————————————————————————————————————————————————————————————————————————————————
|std::deque<TYPE> _name_    |声明一个空的双端队列                                    |
|c.push_front(elem)         |在头部插入一个数据 elem                                 |
|c.pop_front()              |删除头部第一个数据                                      |
|c.push_back(elem)          |在尾部加入一个数据 elem                                 |
|c.pop_back()               |删除最后一个数据                                        |
|c.at(idx) / c[idx]         |通过下标随机访问第 idx 个数据（这是标准 queue 做不到的）|
|c.begin() / c.end()        |支持完整的迭代器操作                                    |
——————————————————————————————————————————————————————————————————————————————————————

### priority_queue：优先队列
**底层是完全二叉树**
———————————————————————————————————————————————————————————————————————————————————————————————————————
|std::priority_queue<int> q_max;                            |声明一个大顶堆（默认：值最大的排在最前   |
|std::priority_queue<int, vector<int>, greater<int>> q_min; |声明一个小顶堆（值最小的排在最前）       |
———————————————————————————————————————————————————————————————————————————————————————————————————————


## 集合：set

1. set：红黑树+去重+自动升序+O(logN)
2. multiset：红黑树+不去重+自动升序+O(logN)
3. unordered_set：哈希表+去重+乱序+O(1~N)

————————————————————————————————————————————————————————————————————————————————————————
|std::set<TYPE> _name_                 |声明一个空的有序列集合（默认升序）             |
|std::set<TYPE, std::greater<TYPE>> _n_|声明一个降序排列的有序列集合                   |
|std::multiset<TYPE> _name_            |声明一个允许元素重复的有序列集合               |
|std::unordered_set<TYPE> _name_       |声明一个无序且去重的集合（基于哈希表）         |
|std::set<int> s = {1, 5, 2, 2}        |带初值的声明（初始化后会自动去重且排序为1,2,5）|
————————————————————————————————————————————————————————————————————————————————————————
**集合内的值一旦插入就无法修改**
——————————————————————————————————————————————————————————————————————————————————————
|s.insert(elem)           |插入元素：若元素已存在（对于 set），则插入失败            |
|s.erase(elem)            |删除元素：根据值直接删除对应的元素                        |
|s.find(elem)             |查找元素：返回指向该元素的迭代器，若没找到则返回 s.end()  |
|s.count(elem)            |计数：返回该元素个数（set只能是0或1；multiset可能>1）     |
|s.size()                 |大小：返回当前集合中元素的总数                            |
|s.empty()                |判断：检查集合是否为空                                    |
|s.clear()                |清空：移除集合中的所有元素                                |
——————————————————————————————————————————————————————————————————————————————————————

用 C++ STL 模拟树和图结构是算法竞赛和面试中的核心基本功。STL 提供了极高的灵活性，能够让我们在几行代码内迅速搭建出各种复杂的拓扑结构。

总结来说，用 STL 模拟树和图主要有**三大通用套路**：

---

## 套路一：邻接表（Adjacency List）—— 最通用的标配

无论是有向图、无向图、网（带权图）还是树，**`vector` 的数组**或 **`vector` 的 `vector**` 都是最常用的表达方式。

### 1. 基础版（无权图/树）

直接用一个容器数组，下标代表起点，容器内存储终点。

```cpp
#include <vector>
using namespace std;

const int MAXN = 10005; 
vector<int> G[MAXN]; // 或者是 vector<vector<int>> G(n);

// 加边函数
void add_edge(int u, int v, bool bidirectional = false) {
    G[u].push_back(v);
    if (bidirectional) {
        G[v].push_back(u); // 无向图或树
    }
}

```

### 2. 升级版（带权图/网）

利用 `pair<int, int>` 将**终点**和**边权**打包。

```cpp
// first: 终点 v, second: 边权 w
vector<pair<int, int>> G[MAXN]; 

void add_edge(int u, int v, int w) {
    G[u].push_back({v, w}); 
}

```

### 3. 拓扑遍历通用模板（以 DFS 为例）

```cpp
void dfs(int u, int fa) { // fa 用于树形结构防止回流，图结构请换用 visited 数组
    for (int v : G[u]) {
        if (v == fa) continue; // 或者是 if(vis[v]) continue;
        // 执行核心逻辑
        dfs(v, u);
    }
}

```

---

## 套路二：动态二叉树 —— 结构体与指针/索引的结合

对于二叉树（如二叉搜索树、线段树、Huffman树），我们通常用结构体配合 STL。为了避免频繁 `new` 导致内存碎片和超时，常用结构体数组 + 索引（下标）模拟指针。

### 1. 数组索引版（推荐，极其高效）

使用 `int` 代替传统指针，`-1` 或 `0` 代表空节点。

```cpp
struct TreeNode {
    int val;
    int left = -1;  // 左孩子的数组下标
    int right = -1; // 右孩子的数组下标
};

vector<TreeNode> tree; // 动态分配树节点池

// 创建新节点并返回其下标
int create_node(int val) {
    tree.push_back({val, -1, -1});
    return tree.size() - 1;
}

```

### 2. 括号表达式/特殊输入建树（如 ZOJ 1097/1011）

配合 `stringstream` 可以非常优雅地解析形如 `(A(B)(C))` 的树结构：

```cpp
#include <sstream>

int parse(stringstream& ss) {
    char ch;
    int val;
    if (!(ss >> ch) || ch == ')') return -1; // 遇到空或右括号返回
    ss >> val; // 读取当前节点值
    int u = create_node(val);
    
    // 递归建立左右子树
    tree[u].left = parse(ss);
    tree[u].right = parse(ss);
    
    ss >> ch; // 读掉匹配的右括号 ')'
    return u;
}

```

---

## 套路三：高级拓扑动态维护 —— 映射与集合

当图的节点**不是连续数字**（例如节点是字符串、离散的大整数），或者需要**动态高效删边、去重**时，需要祭出 `map` 和 `set`。

### 1. 字符串节点 / 离散节点建图

```cpp
#include <map>
#include <set>
#include <string>

// 节点是名字（string），邻接点用 set 存储可以自动去重且按字典序排序
map<string, set<string>> dynamic_G; 

void add_edge(string u, string v) {
    dynamic_G[u].insert(v);
}

```

### 2. 拓扑动态删边（如 Prufer 序列模拟，ZOJ 1097）

如果算法要求频繁寻找“度为 1 的节点”并“断开其连边”，用 `set` 维护邻接表是最简单的（虽然常数略大，但写起来极快）：

```cpp
map<int, set<int>> adj;
map<int, int> degree;

void remove_edge(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
    degree[u]--;
    degree[v]--;
}

```

---

## 💡 核心避坑与优化指南

1. **树与图的边界（Fa 变量 vs Vis 数组）**：
* 在**树**的遍历中，因为没有环，你只需要传入一个 `fa`（父亲节点）参数，遍历时加上 `if (v == fa) continue;` 就能完美防止死循环。
* 在**一般图**中，必须开一个 `vector<bool> vis(n, false);` 并在遍历时标记，否则会陷入环路死循环。


2. **预留空间优化（`reserve`）**：
* 如果已知节点数 $N$，在使用 `vector<int> G[MAXN]` 或 `vector<TreeNode> tree` 之前，先调用 `tree.reserve(N)`。这能防止 `vector` 频繁扩容复制，能显著带来 20%~30% 的常数提速。


3. **点权与边权的分离**：
* **点权**永远建议单独开一个独立数组 `vector<int> weight(N);` 存储，不要强行塞进邻接表里，保持图的拓扑结构和业务数据分离，代码会清晰很多。



掌握了上面三个套路（`vector` 数组、结构体索引、`map/set` 动态维护），你基本可以闭眼写出绝大多数图论与树形题目的数据结构。你目前是在练习哪一类特定的图论算法（如最短路、生成树或树形DP）呢？




# 递归和分治策略

## 递归

### 基本概念

**适用的问题**
1. 题目数据按照递归定义：Fibonacci
2. 问题解法按照递归实现：回溯算法
3. 数据结构适合使用递归：树的遍历和图的搜索

**递归的组成**
1. 边界条件
2. 递归前进段
3. 递归返回段

### 典型例题

- 集合全排列问题：
```
void permute(vector<int>& nums, int start, vector<vector<int>>& res) 
{
    if (start == nums.size()) 
        {
            res.push_back(nums); 
            return; 
        }
    for (int i = start; i < nums.size(); i++) 
    {
        //if(i!=index&&nums[i]==nums[index])
        {
            continue;//去重全排列，开局记得sort
        }
        swap(nums[start], nums[i]);
        permute(nums, start + 1, res);
        swap(nums[start], nums[i]);  // 回溯恢复
    }
}
```
- 整数划分问题：
```
int split(int n,int m)
{
    if(n==1||m==1)
    {
        return 1;
    }
    else if(m>n)
    {
        return split(n,n)
    }
    else if(m==n)
    {
        return split(n,n-1)+1;
    }
    else
    {
        return split(n-m,m)+split(n,m-1);
    }
}
void dfs(int remain, int max_val, vector<int>& path, vector<vector<int>>& ans)
    {
        // 终止条件：需要凑的数字刚好为 0 了
        if (remain == 0) 
        {
            ans.push_back(path);
            return;
        }
        // i 从 min(remain, max_val) 开始，保证我们选的数字不会超过剩下的量，也不会破坏降序规则
        for (int i = min(remain, max_val); i >= 1; i--) 
        {
            // 做出选择
            path.push_back(i);
            
            // 递归向下：还要凑 remain-i，并且下次选的数字不能超过 i
            dfs(remain - i, i, path, ans);
            
            // 撤销选择（回溯），清理现场，为循环的下一次 i 做准备
            path.pop_back();
        }
    }
```


## 分治策略

### 基本概念

**基本步骤**
1. 将原问题分解为若干个与原问题形式相同的子问题
2. 递归的求解子问题直到base case
3. 将子问题的解merge得到原问题的解

**适用的问题**
- 问题具有容易得到的base case
- 能够分解为独立的子问题（满足计算上的独立性）
- 子问题能够merge得到全局解

### 典型例题

1. 二分搜索：数组必须有序O（logN）
```
int binarySearch(const vector<int>& arr,int target)
{
    int left=0;
    int right=arr.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
        {
            return 1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
```

2. 选择问题：找到一个数组中第k小或者第k大的数
**快排管两边，快选管一边。**
**传统太死板，随机保平安。**
**遇到重复多，国旗三路划分完。**
随机快速选择（荷兰国旗三路划分）
```
void partation(int arr[],int l,int r,int x)
{
    First=l;
    Last=r;
    int i=l;
    while(i<=Last)
    {
        if(arr[i]==x)
        {
            i++;
        }
        else if(arr[i]<x)
        {
            swap(arr[i],arr[First]);
            i++;
            First++;
        }
        else
        {
            swap(arr[i],arr[Last]);
            Last--;
        }
    }
}
int RandomSelect(int arr[],int i)
{
    srand((unsigned)time(NULL));
    int ans=0;
    for(int l=0,r=MAX-1;l<=r;)
    {
        int randomIndex=l+rand()%(r-l+1);
        int x=arr[randomIndex];
        partation(arr,l,r,x);
        if(i<First)
        {
            r=First-1;
        }
        else if(i>Last)
        {
            l=Last+1;
        }
        else
        {
            ans=arr[i];
            break;
        }
    }
    return ans;
}
```

带记忆的递归
3. 半数集问题：
```
int solve(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(arr[n]!=0)
    {
        return arr[n];
    }
    int count=1;//包含自身
    for(int i=1;i<=n/2;i++)
    {
        count+=solve(i);
    }
    return arr[n]=count;
}
```
4. 整数因子问题
```
int solve(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(memory.count[n])//这里使用unordered_map而不是vector
    {
        return memory[n];
    }
    int count=1;
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0)
        {
            count+=solve(n/i);
            if(i*i!=n)
            {
                count+=solve(i);
            }
        }
    }
    return memory[n]=count;
}
```

# 动态规划：用空间换时间的算法

## 基本概念：

**适用的条件**
具有无后效性最优子结构（策略上的独立性，计算上的重叠性）

>分治策略适合解决具有互相独立的子问题的问题，自顶向下计算后向上合并
>动态规划则要具有无后效性的最优子结构，策略上独立但是计算上重叠
>未来决策不依赖过去使得自底向上是最优雅的解决

**动态规划步骤**
1. 明确dp数组和下标的定义
2. 找到状态转移方程（递推方程）
3. 初始化dp数组确定边界条件
4. 确定循环顺序

### 典型例题：

1. 矩阵连乘问题（区间DP）
```
// 【步骤 1】初始化基础状态：长度为 1 的区间，代价为 0
    //（由于 vector 默认初始化为 0，这一步在代码中可省略，但逻辑上存在）
    for (int i = 1; i <= n; ++i) 
    {
        dp[i][i] = 0;
    }

    // 【步骤 2】三层循环递推求解
    // 第一层：枚举区间长度 len（从 2 开始，逐步扩大到 n）
    for (int len = 2; len <= n; ++len)
    {
        // 第二层：枚举区间的起点 i（起点 i 的最大值要保证区间不越界）
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len - 1; // 根据起点 i 和长度 len，计算出终点 j
            dp[i][j] = INF; // 求最小值，先初始化为无穷大
            // 第三层：在区间 [i, j) 之间枚举分裂点 k
            // 将区间 [i, j] 划分为左半部分 [i, k] 和右半部分 [k + 1, j]
            for (int k = i; k < j; ++k)
            {
                // 计算当前划分方式的代价：左区间代价 + 右区间代价 + 合并左右区间的代价
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                // 如果找到更小的代价，更新 dp 数组并记录分裂点
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k; 
                }
            }
        }
    }
```

2.最长公共子序列（双序列DP）
```
  for (int i = 1; i <= m; ++i)
  {
        for (int j = 1; j <= n; ++j)
        {
            // 注意：dp 索引比 string 索引大 1，所以对比的是 text1[i-1] 和 text2[j-1]
            if (text1[i - 1] == text2[j - 1])
            {
                // 字符相同：当前字符加入 LCS，长度在左上方状态基础上 +1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // 字符不同：继承【退化一个字符】的两个状态中的最大值
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // 【重构最优解】通过 dp 数组反向回溯，构造出具体的最长公共子序列
    lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            // 当前字符相同，说明属于 LCS，将其加入结果
            lcs_str.push_back(text1[i - 1]);
            // 往左上方对角线回溯
            i--;
            j--;
        } 
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            // 哪个状态值大，往哪个方向回溯
            i--;
        } 
        else
        {
            j--;
        }
    }
    // 因为是反向回溯，最后需要将字符串翻转
    std::reverse(lcs_str.begin(), lcs_str.end());
```

3.最大子段和（线性DP）
```
    dp[0] = nums[0];
    int max_sum = dp[0];

    // 用于追踪最大子段的边界
    int temp_start = 0; // 记录当前候选子段的起点
    start = 0;
    end = 0;
    for (int i = 1; i < n; ++i) 
    {
        // 状态转移
        if (dp[i - 1] > 0) 
        {
            // 前面的子段和为正，有益，加入
            dp[i] = dp[i - 1] + nums[i];
        } 
        else 
        {
            // 前面的子段和为负，无益，丢弃，从当前位置重新开始
            dp[i] = nums[i];
            temp_start = i; // 开启一个新的子段起点
        }
        // 更新全局最大值，并记录当前的起止位置
        if (dp[i] > max_sum) 
        {
            max_sum = dp[i];
            start = temp_start;
            end = i;
        }
    }

int maxSubArrayStandard(const std::vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    int current_max = nums[0]; // 相当于 dp[i-1]
    int global_max = nums[0];  // 记录遍历过程中的全局最大值

    for (size_t i = 1; i < nums.size(); ++i) 
    {
        // 状态转移：是带上前面的一起，还是自己单干？
        current_max = std::max(nums[i], current_max + nums[i]);
        
        // 更新全局最大值
        global_max = std::max(global_max, current_max);
    }

    return global_max;
}
```

4. 0-1背包问题（背包DP）
```
for (int i = 0; i < n; ++i) 
    {
        // 内层循环：逆序遍历背包容量！
        // 只能遍历到当前物品的重量 weights[i]，小于这个重量的容量无法放入该物品，保持原值即可
        for (int j = W; j >= weights[i]; --j) 
        {
            // 状态转移：保持现状，还是放入当前物品？
            dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

for (int i = 1; i <= n; ++i) 
    {
        int w = weights[i - 1]; // 当前物品重量
        int v = values[i - 1];  // 当前物品价值
        for (int j = 1; j <= W; ++j)
        {
            if (j >= w) 
            {
                // 容量足够，可选择放或不放
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + v);
            } 
            else 
            {
                // 容量不足，只能不放
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 【最优解回溯】找出具体放入了哪些物品
    int j = W;
    for (int i = n; i > 0; --i) 
    {
        // 如果当前状态值不等于上一行的状态值，说明放入了第 i 份物品
        if (dp[i][j] != dp[i - 1][j]) 
        {
            selected_items.push_back(i - 1); // 记录物品下标
            j -= weights[i - 1]; // 扣除对应重量
        }
    }
    // 逆序回溯出来的，反转使其按升序排列
    std::reverse(selected_items.begin(), selected_items.end());
```


# 贪心策略：

**每一次抉择都在当前状态下做出最好选择，自顶向下计算不走回头路**

## 贪心的核心要素：
1. 贪心选择性质：可以通过做出局部最优达到全局最优
2. 最优子结构：子问题的解能够凑出总问题的解