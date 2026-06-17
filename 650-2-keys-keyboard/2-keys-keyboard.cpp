class Solution {
public:
    int dp[1001][1001];
    int n;
    const int INF = 1e9;

    int solve(int i, int copied_length) {
        if (i == n) return 0;
        if (i > n) return INF;

        if (dp[i][copied_length] != -1)
            return dp[i][copied_length];

        int copy = INF;
        if (copied_length != i) {
            copy = 1 + solve(i, i);
        }

        int paste = INF;
        if (copied_length > 0 && i + copied_length <= n) {
            paste = 1 + solve(i + copied_length, copied_length);
        }

        return dp[i][copied_length] = min(copy, paste);
    }

    int minSteps(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return solve(1, 0);
    }
};