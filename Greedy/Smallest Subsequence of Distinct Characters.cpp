class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26], vis[26] = {};
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<char> st;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (vis[c]) continue;

            while (!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }

            st.push_back(s[i]);
            vis[c] = 1;
        }

        return string(st.begin(), st.end());
    }
};
