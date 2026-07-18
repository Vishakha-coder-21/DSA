class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            if (x < mn) mn = x;
            else if (x > mx) mx = x;
        }

        while (mx) {
            int t = mn % mx;
            mn = mx;
            mx = t;
        }

        return mn;
    }
};
