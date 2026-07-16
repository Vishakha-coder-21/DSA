class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> a;
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            a.push_back(gcd(x, mx));
        }
        sort(a.begin(), a.end());

        long long ans = 0;
        for (int l = 0, r = a.size() - 1; l < r; ++l, --r)
            ans += gcd(a[l], a[r]);

        return ans;
    }
};
