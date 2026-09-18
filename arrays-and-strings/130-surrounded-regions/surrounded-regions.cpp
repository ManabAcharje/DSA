class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<char>>& board) {

        board[i][j] = 'P';
        for (auto d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                if (board[ni][nj] == 'O') {
                    board[ni][nj] = 'P';
                    dfs(ni, nj, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1, board);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[m - 1][j] == 'O') {
                dfs(m - 1, j, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'P')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};