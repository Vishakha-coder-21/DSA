class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int left_max = nums[0];
        int current_max = nums[0];
        int partition_idx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > current_max) {
                current_max = nums[i];
            }
            if (nums[i] < left_max) {
                left_max = current_max;
                partition_idx = i;
            }
        }

        return partition_idx + 1;
    }
};
