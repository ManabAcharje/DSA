class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int X = 1024;
        const int INF = 1e9;

        vector<vector<int>> dp(m * n, vector<int>(X, INF));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int key = i * n + j;

                for (int x = 0; x < X; x++) {
                    if (i == m - 1 && j == n - 1) {
                        dp[key][x] = x ^ grid[i][j];
                        continue;
                    }

                    int nextXor = x ^ grid[i][j];
                    int down = INF, right = INF;

                    if (i + 1 < m)
                        down = dp[(i + 1) * n + j][nextXor];

                    if (j + 1 < n)
                        right = dp[i * n + j + 1][nextXor];

                    dp[key][x] = min(down, right);
                }
            }
        }

        return dp[0][0];
    }
};