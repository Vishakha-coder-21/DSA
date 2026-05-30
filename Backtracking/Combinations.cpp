class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int start, int n, int k) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }

        int need = k - cur.size();

        for (int i = start; i <= n - need + 1; ++i) {
            cur.push_back(i);
            dfs(i + 1, n, k);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ans.reserve(10000);
        dfs(1, n, k);
        return ans;
    }
};
