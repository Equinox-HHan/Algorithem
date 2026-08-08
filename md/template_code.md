```
template <typename K, typename V>
class LRUCache {
private:
    //LRU核心是双向链表：是需要手动维护前后指针的
    struct Node {
        K key;
        V value;
        Node* prev;
        Node* next;
        Node(K k, V v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    //哈希表Key映射到节点指针
    std::unordered_map<K, Node*> cache_map;
    Node* head; // 虚拟头节点
    Node* tail; // 虚拟尾节点

    // 辅助函数：将节点添加到链表头部 (最近使用)
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 辅助函数：从链表中删除节点
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 辅助函数：移动节点到头部
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    // 辅助函数：移除尾部节点 (最久未访问)
    Node* removeTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    //初始化函数只需要管理dummy节点
    explicit LRUCache(int cap) : capacity(cap) {
        head = new Node(K(), V());
        tail = new Node(K(), V());
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    //查询节点操作：只要查询到必须更新顺序
    bool get(const K& key, V& value) {
        if (cache_map.find(key) == cache_map.end()) {
            return false; // 未命中
        }
        Node* node = cache_map[key];
        moveToHead(node); // 刷新访问顺序
        value = node->value;
        return true;
    }
    //放置节点：如果存在就移动到头部
    //不存在就在头部加上新建节点并考虑负载
    void put(const K& key, const V& value) {
        if (cache_map.find(key) != cache_map.end()) {
            // Key 已存在：更新 Value，移动到头部
            Node* node = cache_map[key];
            node->value = value;
            moveToHead(node);
        } else {
            // Key 不存在：创建新节点
            Node* newNode = new Node(key, value);
            cache_map[key] = newNode;
            addToHead(newNode);

            // 超过容量，淘汰尾部
            if (cache_map.size() > capacity) {
                Node* removed = removeTail();
                cache_map.erase(removed->key);
                delete removed;
            }
        }
    }
};


template <typename K, typename V>
class LFUCache {
private:
    //CPP提供了强大的STL做数据结构支撑
    //直接使用list双向列表不用手动写指针
    struct Node {
        K key;
        V value;
        int freq;
        Node(K k, V v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity;
    int min_freq;

    // key -> Node 在 std::list 中的迭代器
    std::unordered_map<K, typename std::list<Node>::iterator> key_table;
    
    // freq -> 保存该频率所有 Node 的双向链表 (最新访问的在 list 头部)
    std::unordered_map<int, std::list<Node>> freq_table;

    // 辅助函数：增加节点的频率
    //注意函数传入参数是迭代器
    void increaseFreq(typename std::list<Node>::iterator node_it) {
        K key = node_it->key;
        V val = node_it->value;
        int freq = node_it->freq;

        // 从原频率链表中删除
        freq_table[freq].erase(node_it);
        
        // 如果原频率链表为空，且该频率刚好是 min_freq，更新 min_freq
        if (freq_table[freq].empty()) {
            freq_table.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }

        // 插入到 freq + 1 的链表头部
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
    }

public:
    //只需要初始化最小频率
    explicit LFUCache(int cap) : capacity(cap), min_freq(0) {}

    //访问操作：存在Key则必须更新访问频率
    bool get(const K& key, V& value) {
        if (capacity == 0 || key_table.find(key) == key_table.end()) {
            return false;
        }

        auto node_it = key_table[key];
        value = node_it->value;
        
        // 更新访问频率
        increaseFreq(node_it);
        return true;
    }
    
    //改写函数：存在Key则改写Value并更新访问频率
    //不存在则考虑负载然后新建节点
    void put(const K& key, const V& value) {
        if (capacity == 0) return;

        auto it = key_table.find(key);
        if (it != key_table.end()) {
            // Key 已存在：更新 Value，并增加频率
            auto node_it = it->second;
            node_it->value = value;
            increaseFreq(node_it);
        } else {
            // 容量已满，进行淘汰
            if (key_table.size() >= capacity) {
                // 拿到 min_freq 对应的链表末尾节点 (最久未使用的节点)
                auto& min_freq_list = freq_table[min_freq];
                Node deleted_node = min_freq_list.back();
                
                key_table.erase(deleted_node.key);
                min_freq_list.pop_back();

                if (min_freq_list.empty()) {
                    freq_table.erase(min_freq);
                }
            }

            // 插入新节点，新节点初始 freq 为 1
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            min_freq = 1; // 新节点插入后，全局最小频率必定重置为 1
        }
    }
};
```