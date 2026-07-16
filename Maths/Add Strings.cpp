class Solution {
public:
    string addStrings(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        while (i >= 0 || j >= 0 || c) {
            if (i >= 0) c += a[i--] - '0';
            if (j >= 0) c += b[j--] - '0';
            ans += c % 10 + '0';
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
