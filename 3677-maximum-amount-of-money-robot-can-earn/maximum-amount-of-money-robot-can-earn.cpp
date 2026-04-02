class Solution {
public:
    int m, n;
    int dp[501][501][3];
    bool vis[501][501][3];

    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if (i >= m || j >= n) return INT_MIN;

        if (vis[i][j][k]) return dp[i][j][k];

        // destination
        if (i == m - 1 && j == n - 1) {
            vis[i][j][k] = true;
            if (coins[i][j] < 0 && k < 2)
                return dp[i][j][k] = 0;
            return dp[i][j][k] = coins[i][j];
        }

        int right = solve(i, j + 1, k, coins);
        int down  = solve(i + 1, j, k, coins);

        int bestNext = max(right, down);

        int ans;

        if (coins[i][j] < 0) {
            if (k < 2) {
                int kill = max(
                    solve(i, j + 1, k + 1, coins),
                    solve(i + 1, j, k + 1, coins)
                );

                int not_kill = (bestNext == INT_MIN) ? INT_MIN : coins[i][j] + bestNext;

                ans = max(kill, not_kill);
            } else {
                ans = (bestNext == INT_MIN) ? INT_MIN : coins[i][j] + bestNext;
            }
        } else {
            ans = (bestNext == INT_MIN) ? INT_MIN : coins[i][j] + bestNext;
        }

        vis[i][j][k] = true;
        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        memset(vis, false, sizeof(vis));

        return solve(0, 0, 0, coins);
    }
};