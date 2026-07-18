class Solution {
public:
    int ans = 0;

    void dfs(int n, int col, int diag1, int diag2) {
        if (col == (1 << n) - 1) {
            ans++;
            return;
        }

        int free = ((1 << n) - 1) & ~(col | diag1 | diag2);

        while (free) {
            int p = free & -free;   // rightmost available position
            free -= p;
            dfs(n, col | p, (diag1 | p) << 1, (diag2 | p) >> 1);
        }
    }

    int totalNQueens(int n) {
        dfs(n, 0, 0, 0);
        return ans;
    }
};
