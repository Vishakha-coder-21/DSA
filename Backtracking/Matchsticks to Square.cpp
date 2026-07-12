class Solution {
public:
    bool dfs(vector<int>& a, vector<int>& side, int i, int target) {
        if (i == a.size())
            return side[0] == target && side[1] == target &&
                   side[2] == target && side[3] == target;

        for (int j = 0; j < 4; j++) {
            if (side[j] + a[i] > target) continue;

            side[j] += a[i];
            if (dfs(a, side, i + 1, target)) return true;
            side[j] -= a[i];

            if (side[j] == 0) break;   // prune equivalent states
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) return false;

        vector<int> side(4);

        return dfs(matchsticks, side, 0, target);
    }
};
