class NumMatrix {
public:
    int m, n;
    vector<vector<int>> pre;

    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        pre.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int rowSum = 0;  // avoids repeated addition
            for (int j = 0; j < n; j++) {
                rowSum += matrix[i][j];

                if (i == 0)
                    pre[i][j] = rowSum;
                else
                    pre[i][j] = pre[i-1][j] + rowSum;
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int res = pre[r2][c2];

        if (r1 > 0) res -= pre[r1-1][c2];
        if (c1 > 0) res -= pre[r2][c1-1];
        if (r1 > 0 && c1 > 0) res += pre[r1-1][c1-1];

        return res;
    }
};

