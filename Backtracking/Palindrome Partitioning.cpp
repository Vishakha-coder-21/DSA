class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> pal;
    int n;

    void dfs(const string& s, int start) {
        if (start == n) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (!pal[start][end]) continue;

            path.emplace_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();

        pal.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                pal[i][j] = (s[i] == s[j]) &&
                           (j - i < 2 || pal[i + 1][j - 1]);
            }
        }

        dfs(s, 0);
        return ans;
    }
};
