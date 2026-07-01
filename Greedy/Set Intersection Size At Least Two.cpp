class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    }

public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = 0;
        int a = -1, b = -1;

        for (const auto &v : intervals) {
            int l = v[0], r = v[1];

            if (l <= a) continue;

            if (l <= b) {
                ++ans;
                a = b;
                b = r;
            } else {
                ans += 2;
                a = r - 1;
                b = r;
            }
        }
        return ans;
    }
};
