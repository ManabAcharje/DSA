class Solution {
public:
    int dir[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    void build(int i, int j, int d, int val, vector<vector<int>> &matrix) {
        int n = matrix.size();
        matrix[i][j] = val;

        // base case
        if (val == n * n)
            return;
        
        int x = i + dir[d][0];
        int y = j + dir[d][1];

        if (x < 0 || x >= n || y < 0 || y >= n || matrix[x][y] >= 1) 
        {
            d = (d + 1) % 4;
            x = i + dir[d][0];
            y = j + dir[d][1];
        }
        build(x, y, d, val + 1, matrix);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

         build(0, 0, 0, 1, matrix);
         return matrix;
    }
};