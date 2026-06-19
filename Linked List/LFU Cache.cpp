class LFUCache {
private:
    struct Node {
        int value;
        int freq;
        list<int>::iterator it;
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node> cache;
    unordered_map<int, list<int>> freqList;

    void updateFreq(int key) {
        auto &node = cache[key];
        int freq = node.freq;

        freqList[freq].erase(node.it);

        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        node.freq++;

        freqList[node.freq].push_front(key);
        node.it = freqList[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;

        cache.reserve(capacity);
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        updateFreq(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (cache.count(key)) {
            cache[key].value = value;
            updateFreq(key);
            return;
        }

        if (cache.size() == capacity) {
            int evictKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            cache.erase(evictKey);
        }

        freqList[1].push_front(key);

        cache[key] = {
            value,
            1,
            freqList[1].begin()
        };

        minFreq = 1;
    }
};
