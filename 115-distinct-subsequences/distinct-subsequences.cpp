class Solution {
public:
    string s, t;
    int m, n;
    long long dp[1001][1001];

    long long solve(int i, int j) {
        if (j == m)
            return 1;

        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = solve(i + 1, j + 1) + solve(i + 1, j);
        }

        return dp[i][j] = solve(i + 1, j);
    }

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;

        n = s.size();
        m = t.size();

        memset(dp, -1, sizeof(dp));

        if (n < m)
            return 0;

        return solve(0, 0);
    }
};