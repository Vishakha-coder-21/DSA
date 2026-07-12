class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (int &x : arr)
            x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;

        return arr;
    }
};
