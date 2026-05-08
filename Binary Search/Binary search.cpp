class Solution {
public:
    int search(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m] == t) return m;
            (a[m] < t) ? l = m + 1 : r = m - 1;
        }
        return -1;
    }
};
