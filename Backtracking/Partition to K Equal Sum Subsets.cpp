class Solution {
public:
    bool backtrack(vector<int>& nums, vector<int>& bucket, int idx, int target) {
        if (idx == nums.size())
            return true;

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[idx] > target)
                continue;

            bucket[i] += nums[idx];

            if (backtrack(nums, bucket, idx + 1, target))
                return true;

            bucket[i] -= nums[idx];

            // Pruning 1: avoid identical bucket states
            if (i > 0 && bucket[i] == bucket[i - 1])
                continue;

            // Pruning 2: don't try other empty buckets
            if (bucket[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> bucket(k, 0);

        return backtrack(nums, bucket, 0, target);
    }
};
