class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int r = 0; r<k/2; r++) {
            for (int c = 0; c < k; c++) {

                int r1=x+r;
                int r2=x+k-1-r;

                swap(grid[r1][y+c],grid[r2][y+c]);
            }
        }
        return grid;
    }
};