class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos;
        vector<int> dig;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int n = dig.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> pref(n + 1, 0);
        vector<int> prefSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = (pref[i] * 10 + dig[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + dig[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            int cnt = R - L + 1;

            long long x = (pref[R + 1] - pref[L] * pow10[cnt]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};
