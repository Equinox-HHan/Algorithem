```
#include <iostream>
#include <string>
#include <vector>

class TrieArray {
private:
    // 定义树的一个节点
    struct TrieNode {
        // 26 个槽位，分别对应 'a' 到 'z'
        // 如果 children[0] 不是 nullptr，说明后面连着以 'a' 开头的分支
        TrieNode* children[26];

        // 标记：从根节点走到当前这个节点，拼出的字符串是否算作一个完整的单词
        // 比如插入了 "app"，那么走完 'a'->'p'->'p' 后，最后一个 'p' 节点的 isEnd 为 true
        // 此时如果没插入过 "ap"，那么第 1 个 'p' 节点的 isEnd 仍是 false
        bool isEnd;

        // 构造函数：初始化一个新节点
        TrieNode() : isEnd(false) {
            // 一开始这个新节点没有任何子路标，全部置空
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }

        // 析构函数：释放当前节点下的所有子节点，防止内存泄漏
        ~TrieNode() {
            for (int i = 0; i < 26; ++i) {
                // delete nullptr 是安全的；如果有子节点，会递归释放
                delete children[i];
            }
        }
    };

    // 树的根节点，根节点本身不代表任何字母，它只是起点
    TrieNode* root;

public:
    // 构造函数：创建一棵空树
    TrieArray() {
        root = new TrieNode();
    }

    // 析构函数：整棵树销毁时，从根节点开始递归清理所有申请的内存
    ~TrieArray() {
        delete root;
    }

    /**
     * 1. 插入单词 (insert)
     * 过程：像走迷宫一样，沿着单词的每个字母往下走。
     * 遇到没有路（nullptr）就修一条新路（new TrieNode），走到最后一个字母打上结束标记。
     */
    void insert(const std::string& word) {
        // 每次都从根节点出发
        TrieNode* curr = root;

        for (char ch : word) {
            // 利用 ASCII 码计算字符对应的数组下标
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // ...
            // 'z' - 'a' = 25
            int index = ch - 'a';

            // 检查当前节点是否有通向这个字母的子节点
            if (curr->children[index] == nullptr) {
                // 没有这条路，说明之前没存过这个前缀，创建一个新节点（铺路）
                curr->children[index] = new TrieNode();
            }

            // 走过去，将指针移动到下一个子节点
            curr = curr->children[index];
        }

        // 单词的全部字母遍历完毕，说明从根到当前节点拼成了完整单词
        // 在末尾节点打上“单词终点”标记
        curr->isEnd = true;
    }

    /**
     * 2. 搜索完整单词 (search)
     * 过程：沿字母往下找，如果半路没路了，或者虽然走完了但末尾没有 isEnd 标记，都算失败。
     */
    bool search(const std::string& word) const {
        // 先借用 findPrefix 沿途走到底
        const TrieNode* node = findPrefix(word);

        // 必须满足两个条件：
        // 1. node != nullptr：整个单词的所有字母都能完整走通
        // 2. node->isEnd == true：不仅能走通，而且在末尾明确记录过这是一个完整单词
        // （例如：插入了 "apple"，查找 "app" 时，能完整走通，但第二个 'p' 处的 isEnd 为 false，所以返回 false）
        return node != nullptr && node->isEnd;
    }

    /**
     * 3. 检查前缀匹配 (startsWith)
     * 过程：只要能沿着前缀的所有字符走到底即可，不管最后一个节点是不是完整单词。
     */
    bool startsWith(const std::string& prefix) const {
        // 只要能够顺着路径顺利走完整个前缀，就返回 true
        return findPrefix(prefix) != nullptr;
    }

private:
    /**
     * 核心辅助函数：沿着字符串路径寻找最后的那个节点
     * 如果字符串走得通，返回最后一个字符对应的节点指针
     * 如果半路走不通（中间有断点），返回 nullptr
     */
    const TrieNode* findPrefix(const std::string& prefix) const {
        const TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            // 如果当前字符对应的分支不存在，说明根本没有这个前缀
            if (curr->children[index] == nullptr) {
                return nullptr; // 迷宫断路，直接失败
            }

            // 顺着分支继续往下走
            curr = curr->children[index];
        }

        // 走完全部字符，返回停靠的节点
        return curr;
    }
};
```
```
#include <iostream>
#include <string>
#include <unordered_map>

class TrieMap {
private:
    struct TrieNode {
        // 使用哈希表维护子节点映射关系
        // key: 字符 (如 'A', '9', '#')
        // value: 指向子节点的指针
        std::unordered_map<char, TrieNode*> children;

        // 同样用来记录“从根走到这里是否构成一个完整单词”
        bool isEnd;

        TrieNode() : isEnd(false) {}

        // 析构函数：遍历哈希表中所有存在的子节点，递归释放内存
        ~TrieNode() {
            for (auto& pair : children) {
                delete pair.second; // pair.second 是 TrieNode* 指针
            }
        }
    };

    TrieNode* root;

public:
    TrieMap() {
        root = new TrieNode();
    }

    ~TrieMap() {
        delete root;
    }

    /**
     * 1. 插入单词 (insert)
     */
    void insert(const std::string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            // 在当前节点的哈希表中查找字符 ch 是否已经建过分支
            // curr->children.find(ch) == curr->children.end() 相当于“哈希表里找不到 ch”
            if (curr->children.find(ch) == curr->children.end()) {
                // 没有这个分支，现场 new 一个新节点塞进哈希表
                curr->children[ch] = new TrieNode();
            }

            // 顺着哈希表记录的路径，移动到子节点
            curr = curr->children[ch];
        }

        // 走完整个单词，标记结束
        curr->isEnd = true;
    }

    /**
     * 2. 搜索完整单词 (search)
     */
    bool search(const std::string& word) const {
        const TrieNode* node = findPrefix(word);
        // 走得通 且 末尾有结束标记
        return node != nullptr && node->isEnd;
    }

    /**
     * 3. 检查前缀匹配 (startsWith)
     */
    bool startsWith(const std::string& prefix) const {
        // 只要顺着前缀走得通就判定成功
        return findPrefix(prefix) != nullptr;
    }

private:
    /**
     * 辅助查找函数：顺着字符逐步在哈希表中查路
     */
    const TrieNode* findPrefix(const std::string& prefix) const {
        const TrieNode* curr = root;

        for (char ch : prefix) {
            // 查哈希表看当前节点是否包含这个字符
            auto it = curr->children.find(ch);

            if (it == curr->children.end()) {
                // 哈希表里没存过这个字符，说明前缀走不通
                return nullptr;
            }

            // it->second 即为子节点的地址，指针往前挪步
            curr = it->second;
        }

        return curr;
    }
};
```