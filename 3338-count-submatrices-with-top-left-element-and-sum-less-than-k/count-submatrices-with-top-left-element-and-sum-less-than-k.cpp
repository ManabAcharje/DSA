class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // we will approach it by taking grid of [i][j] is the last bottom left
        // point of the sub matrix  and if sum is <=k ans++;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        // prefix row will be helpful but if we kepp it computing as we go along
        // would be efficiient

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j]=((j>=1)?grid[i][j-1] : 0 )+((i>=1)?grid[i-1][j]:0 )+ grid[i][j] - ((i>=1 && j>=1 )?grid[i-1][j-1]:0);
                if(grid[i][j]<=k)ans++;
            }
        }
        return ans;
    }
};