class Solution {
    struct Trie {
        Trie* next[26] = {};
        string word = "";
    };

    Trie* root = new Trie();
    vector<string> ans;
    int m, n;

    void insert(string &w) {
        Trie* p = root;
        for (char c : w) {
            int i = c - 'a';
            if (!p->next[i]) p->next[i] = new Trie();
            p = p->next[i];
        }
        p->word = w;
    }

    void dfs(vector<vector<char>>& b, int i, int j, Trie* node) {
        char c = b[i][j];
        if (c == '#' || !node->next[c - 'a']) return;

        node = node->next[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear();          // avoid duplicates
        }

        b[i][j] = '#';

        if (i > 0) dfs(b, i - 1, j, node);
        if (j > 0) dfs(b, i, j - 1, node);
        if (i < m - 1) dfs(b, i + 1, j, node);
        if (j < n - 1) dfs(b, i, j + 1, node);

        b[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for (auto &w : words) insert(w);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);

        return ans;
    }
};
