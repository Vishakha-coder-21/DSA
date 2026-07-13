#pragma GCC optimize("O3")
#pragma GCC target("avx2")

static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n < 2) return 0;

        int max_len = 0;
        int left = 0, right = 0;

        // Left-to-right pass
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right-to-left pass
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }

            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return max_len;
    }
};
