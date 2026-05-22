class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        
        for (int n : nums)
            x |= n;

        return x << (nums.size() - 1);
    }
};
