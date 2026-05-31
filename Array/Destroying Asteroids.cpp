class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        static int freq[100001];
        
        for (int x : asteroids)
            ++freq[x];

        long long cur = mass;

        for (int v = 1; v <= 100000; ++v) {
            int cnt = freq[v];

            while (cnt--) {
                if (cur < v) {
                    for (int i : asteroids) --freq[i];
                    return false;
                }
                cur += v;
            }
        }

        for (int i : asteroids) --freq[i];
        return true;
    }
};
