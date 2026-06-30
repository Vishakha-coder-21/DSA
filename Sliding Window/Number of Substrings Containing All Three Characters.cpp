class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
            ans += min(last[0], min(last[1], last[2])) + 1;
        }
        return ans;
    }
};
