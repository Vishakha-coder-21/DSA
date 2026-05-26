class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    inline void dfs(int idx, int target, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (nums[i] > target) break;

            curr.push_back(nums[i]);

            dfs(i, target - nums[i], nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // important for pruning
        dfs(0, target, nums);
        return ans;
    }
};
