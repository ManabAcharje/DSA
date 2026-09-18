class Solution {
public:
    int m, n;
    // Use a vector of vectors of vectors
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return INT_MIN;
        
        int cost = (grid[i][j] == 0 ? 0 : 1);
        if (k < cost) return INT_MIN;

        if (i == m - 1 && j == n - 1) return grid[i][j];

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int right = solve(i, j + 1, k - cost, grid);
        int down = solve(i + 1, j, k - cost, grid);

        int res = max(right, down);
        
        // Ensure we don't add to INT_MIN which causes overflow
        if (res != INT_MIN) res += grid[i][j];
        
        return dp[i][j][k] = res;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        // Initialize DP table on the heap
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        int ans = solve(0, 0, k, grid);
        return (ans < 0 ? -1 : ans);
    }
};