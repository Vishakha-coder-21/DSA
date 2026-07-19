class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(), nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0LL);

        while (l < r) {
            long long m = (l + r) / 2;
            int cnt = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > m) {
                    cnt++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (cnt > k) l = m + 1;
            else r = m;
        }

        return l;
    }
};
