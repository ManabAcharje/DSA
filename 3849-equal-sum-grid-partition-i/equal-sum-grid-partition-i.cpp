class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long > rowPref(m, 0);
        vector<long long> colPref(n, 0);

        // Row prefix
        for (int i = 0; i < m; i++) {
            long long  sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            rowPref[i] = sum + (i > 0 ? rowPref[i - 1] : 0);
        }

        // Column prefix
        for (int j = 0; j < n; j++) {
            long long  sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            colPref[j] = sum + (j > 0 ? colPref[j - 1] : 0);
        }

        long long  total = rowPref[m - 1];

        // Horizontal cut
        for (int i = 0; i < m - 1; i++) {
            if (rowPref[i] == total - rowPref[i])
                return true;
        }

        // Vertical cut
        for (int j = 0; j < n - 1; j++) {
            if (colPref[j] == total - colPref[j])
                return true;
        }

        return false;
    }
};