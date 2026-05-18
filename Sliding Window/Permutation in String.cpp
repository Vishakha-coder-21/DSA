class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> cnt(26, 0);

        // count s1
        for (char c : s1) cnt[c - 'a']++;

        int left = 0;

        for (int right = 0; right < m; right++) {
            cnt[s2[right] - 'a']--;

            // window size > n → shrink
            if (right - left + 1 > n) {
                cnt[s2[left] - 'a']++;
                left++;
            }

            // check match
            if (all_of(cnt.begin(), cnt.end(), [](int x){ return x == 0; }))
                return true;
        }

        return false;
    }
};
