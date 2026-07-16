class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(a[i][j], a[j][i]);
        for (auto &r : a) reverse(r.begin(), r.end());
    }
};
