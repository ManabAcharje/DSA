class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<pair<int,int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},         {0,1},
            {1,-1},{1,0},{1,1}
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0,0});
        visited[0][0] = true;

        int length = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n-1 && y == n-1)
                    return length;

                for (auto &[dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 &&
                        nx < n && ny < n &&
                        !visited[nx][ny] &&
                        grid[nx][ny] == 0) {

                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            length++;
        }

        return -1;
    }
};