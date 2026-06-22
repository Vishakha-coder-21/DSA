class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node *head, *tail;

    inline void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    inline void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        mp.reserve(capacity * 2);

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = mp.find(key);

        if (it == mp.end())
            return -1;

        Node* node = it->second;

        removeNode(node);
        addToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            Node* node = it->second;
            node->value = value;

            removeNode(node);
            addToFront(node);
            return;
        }

        Node* node = new Node(key, value);

        mp[key] = node;
        addToFront(node);

        if ((int)mp.size() > capacity) {
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};
