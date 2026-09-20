class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        // target == 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // i = 1 means original i = 0
        for (int i = 1; i <= n; i++) {

            for (int target = 1; target <= amount; target++) {

                // not_take
                int not_take = dp[i - 1][target];

                // take
                int take = INT_MAX;

                if (target >= coins[i - 1] &&
                    dp[i][target - coins[i - 1]] != INT_MAX) {

                    take = 1 + dp[i][target - coins[i - 1]];
                }

                dp[i][target] = min(take, not_take);
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};