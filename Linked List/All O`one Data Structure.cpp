class AllOne {
    struct Bucket {
        int cnt;
        unordered_set<string> keys;
        Bucket(int c) : cnt(c) {}
    };

    list<Bucket> buckets;

    unordered_map<string, list<Bucket>::iterator> pos;

public:
    AllOne() {
        pos.reserve(50000);
    }

    void inc(string key) {
        if (!pos.count(key)) {
            if (buckets.empty() || buckets.front().cnt != 1)
                buckets.emplace_front(1);

            buckets.front().keys.insert(key);
            pos[key] = buckets.begin();
            return;
        }

        auto cur = pos[key];
        auto nxt = next(cur);

        if (nxt == buckets.end() || nxt->cnt != cur->cnt + 1)
            nxt = buckets.insert(nxt, Bucket(cur->cnt + 1));

        nxt->keys.insert(key);
        pos[key] = nxt;

        cur->keys.erase(key);

        if (cur->keys.empty())
            buckets.erase(cur);
    }

    void dec(string key) {
        auto cur = pos[key];

        if (cur->cnt == 1) {
            cur->keys.erase(key);
            pos.erase(key);

            if (cur->keys.empty())
                buckets.erase(cur);

            return;
        }

        auto prv = (cur == buckets.begin()) ? buckets.end() : prev(cur);

        if (cur == buckets.begin() || prv->cnt != cur->cnt - 1)
            prv = buckets.insert(cur, Bucket(cur->cnt - 1));

        prv->keys.insert(key);
        pos[key] = prv;

        cur->keys.erase(key);

        if (cur->keys.empty())
            buckets.erase(cur);
    }

    string getMaxKey() {
        return buckets.empty()
            ? ""
            : *buckets.back().keys.begin();
    }

    string getMinKey() {
        return buckets.empty()
            ? ""
            : *buckets.front().keys.begin();
    }
};
