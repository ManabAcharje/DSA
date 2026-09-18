class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> flip(m, vector<int>(n, 0));
        vector<vector<int>> dir = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                                   {-1, -1}, {1, -1}, {1, 1},  {-1, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                int dead = 0;
                for (auto& d : dir) 
                {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                        if (board[ni][nj] == 0)
                            dead++;
                        else
                            live++;
                    }
                }
                if (board[i][j]) {
                    if (live < 2 || live > 3)
                        flip[i][j] = 1;

                } else {
                    if (live == 3)
                        flip[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flip[i][j])
                    board[i][j] = !board[i][j];
            }
        }
        return;
    }
};