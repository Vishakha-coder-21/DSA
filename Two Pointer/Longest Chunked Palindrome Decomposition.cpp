class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();

        for (int len = 1; len <= n / 2; len++) {
            if (text.substr(0, len) == text.substr(n - len, len))
                return 2 + longestDecomposition(text.substr(len, n - 2 * len));
        }

        return n ? 1 : 0;
    }
};
