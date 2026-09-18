class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        vector<vector<int>> curr(n, vector<int>(2, 0));
        vector<vector<int>> prev;

        
        for (int j = 0; j < n; j++) {
            int x = (grid[0][j] == 'X');
            int y = (grid[0][j] == 'Y');

            curr[j][0] = (j > 0 ? curr[j - 1][0] : 0) + x;
            curr[j][1] = (j > 0 ? curr[j - 1][1] : 0) + y;

            if (curr[j][0] == curr[j][1] && curr[j][0] >= 1)
                ans++;
        }

        prev = curr;

        for (int i = 1; i < m; i++) {
            curr = vector<vector<int>>(n, vector<int>(2, 0));

            for (int j = 0; j < n; j++) {
                int x = (grid[i][j] == 'X');
                int y = (grid[i][j] == 'Y');

                curr[j][0] = prev[j][0] 
                           + (j >= 1 ? curr[j - 1][0] : 0) 
                           - (j >= 1 ? prev[j - 1][0] : 0) 
                           + x;

                curr[j][1] = prev[j][1] 
                           + (j >= 1 ? curr[j - 1][1] : 0) 
                           - (j >= 1 ? prev[j - 1][1] : 0) 
                           + y;

                if (curr[j][0] == curr[j][1] && curr[j][0] >= 1)
                    ans++;
            }

            prev = curr;
        }

        return ans;
    }
};