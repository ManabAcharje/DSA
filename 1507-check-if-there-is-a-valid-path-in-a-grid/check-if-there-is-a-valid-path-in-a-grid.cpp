class Solution {
public:

    vector<vector<int>>dirs = {
        {}, // dummy for 0
        {2, 3}, // 1: left, right
        {0, 1}, // 2: up, down
        {2, 1}, // 3: left, down
        {3, 1}, // 4: right, down
        {2, 0}, // 5: left, up
        {3, 0}  // 6: right, up
    };
    bool hasValidPath(vector<vector<int>>& grid)
     {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, grid, visited);
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (r == m - 1 && c == n - 1)
            return true;
        visited[r][c] = true;
        int type = grid[r][c];
        for (int dirIdx : dirs[type]) {
            int nr = r + dr[dirIdx];
            int nc = c + dc[dirIdx];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                int nextType = grid[nr][nc];
                if (canConnectBack(dirIdx, nextType)) {
                    if (dfs(nr, nc, grid, visited))
                        return true;
                }
            }
        }
        return false;
    }
    bool canConnectBack(int moveDir, int nextStreet) {
        // Opposite directions: Up(0)<->Down(1), Left(2)<->Right(3)
        int opposite = moveDir ^ 1;
        for (int d : dirs[nextStreet]) {
            if (d == opposite)
                return true;
        }
        return false;
    }
};