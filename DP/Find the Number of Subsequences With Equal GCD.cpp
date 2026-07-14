class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int subsequencePairCount(vector<int>& nums) {
        static int dp[201][201], ndp[201][201];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int x : nums) {
            memset(ndp, 0, sizeof(ndp));

            for (int g1 = 0; g1 <= 200; ++g1) {
                for (int g2 = 0; g2 <= 200; ++g2) {
                    int cur = dp[g1][g2];
                    if (!cur) continue;

                    // skip
                    ndp[g1][g2] = (ndp[g1][g2] + cur) % MOD;

                    // put in seq1
                    int ng1 = g1 ? gcd(g1, x) : x;
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                    // put in seq2
                    int ng2 = g2 ? gcd(g2, x) : x;
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;
        for (int g = 1; g <= 200; ++g)
            ans = (ans + dp[g][g]) % MOD;

        return (int)ans;
    }
};
