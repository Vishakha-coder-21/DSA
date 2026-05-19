class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int sum = 0;
        int ans = n + 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                int len = right - left + 1;

                if (len < ans)
                    ans = len;

                sum -= nums[left++];
            }
        }

        return ans == n + 1 ? 0 : ans;
    }
};
