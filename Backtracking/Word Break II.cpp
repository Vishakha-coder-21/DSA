class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    int n;
    string s;

    vector<string> dfs(int start) {
        if (memo.count(start))
            return memo[start];

        vector<string> res;

        if (start == n) {
            res.push_back("");
            return memo[start] = res;
        }

        for (int len = 1; len <= 10 && start + len <= n; ++len) {
            string word = s.substr(start, len);

            if (!dict.count(word))
                continue;

            vector<string> suffix = dfs(start + len);

            for (string &str : suffix) {
                if (str.empty())
                    res.push_back(word);
                else
                    res.push_back(word + " " + str);
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string str, vector<string>& wordDict) {
        s = str;
        n = s.size();

        dict.insert(wordDict.begin(), wordDict.end());

        return dfs(0);
    }
};
