class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark visited

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            for (int k = 0; k < sz; k++) {
                auto [i, j] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    // valid move
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == '.') {

                        // check exit (boundary + not entrance)
                        if (ni == 0 || ni == m-1 || nj == 0 || nj == n-1) {
                            return steps;
                        }

                        maze[ni][nj] = '+'; // mark visited
                        q.push({ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};