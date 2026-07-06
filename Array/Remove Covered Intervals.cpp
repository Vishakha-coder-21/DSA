class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int maxR = -1;
        int cnt = 0;

        for (int i = 0, n = intervals.size(); i < n; ++i) {
            if (intervals[i][1] > maxR) {
                ++cnt;
                maxR = intervals[i][1];
            }
        }
        return cnt;
    }
};
