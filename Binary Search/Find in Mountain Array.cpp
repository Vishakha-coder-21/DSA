class Solution {
    int bs(MountainArray &a, int l, int r, int t, bool inc) {
        while (l <= r) {
            int m = (l + r) / 2, x = a.get(m);
            if (x == t) return m;
            if ((x < t) == inc) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &a) {
        int l = 0, r = a.length() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a.get(m) < a.get(m + 1)) l = m + 1;
            else r = m;
        }

        int ans = bs(a, 0, l, target, true);
        return ans != -1 ? ans : bs(a, l + 1, a.length() - 1, target, false);
    }
};
