class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {

        if (idx == word.size())
            return true;

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[idx])
            return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);

        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        int freqBoard[128] = {0};
        int freqWord[128] = {0};

        for (auto& row : board)
            for (char ch : row)
                freqBoard[ch]++;

        for (char ch : word)
            freqWord[ch]++;

        for (int i = 0; i < 128; i++)
            if (freqWord[i] > freqBoard[i])
                return false;

        if (freqBoard[word[0]] > freqBoard[word.back()])
            reverse(word.begin(), word.end());

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == word[0] &&
                    dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};
