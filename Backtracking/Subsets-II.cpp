class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int idx, vector<int>& nums) {

        ans.push_back(curr);

        for (int i = idx; i < nums.size(); ++i) {

            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            dfs(i + 1, nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        ans.reserve(1 << nums.size());

        dfs(0, nums);

        return ans;
    }
};
