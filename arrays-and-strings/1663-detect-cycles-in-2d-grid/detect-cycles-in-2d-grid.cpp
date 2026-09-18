class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& grid, int i, int j,
             int pi, int pj, char target) {

        visited[i][j] = true;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if (grid[ni][nj] != target)
                continue;

            // Ignore the parent
            if (ni == pi && nj == pj)
                continue;

            if (visited[ni][nj])
                return true;

            if (dfs(grid, ni, nj, i, j, target))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }

        return false;
    }
};