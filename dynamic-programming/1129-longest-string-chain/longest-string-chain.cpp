class Solution {
public:
    vector<string> words;
    int n;
    vector<vector<int>> dp;

    bool oneCharDiff(int i, int j) {
        if (words[i].size() != words[j].size() + 1)
            return false;

        int p1 = 0, p2 = 0;
        bool skipped = false;

        while (p1 < words[i].size() && p2 < words[j].size()) {
            if (words[i][p1] == words[j][p2]) {
                p1++;
                p2++;
            } else {
                if (skipped)
                    return false;
                skipped = true;
                p1++;
            }
        }
        return true;
    }

    int solve(int i, int last_picked) {
        if (i == n)
            return 0;

        if (dp[i][last_picked + 1] != -1)
            return dp[i][last_picked + 1];

        int not_pick = solve(i + 1, last_picked);
        int pick = 0;

        if (last_picked == -1 || oneCharDiff(i, last_picked))
            pick = 1 + solve(i + 1, i);

        return dp[i][last_picked + 1] = max(pick, not_pick);
    }

    int longestStrChain(vector<string>& w) {
        words = w;
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 return a.size() < b.size();
             });

        n = words.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, -1);
    }
};