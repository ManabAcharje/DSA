class Solution {
public:
    const int M = 1e9+7;
    int m, n;

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int dp[51][51][51];

    int solve(int i, int j, int move) {
        // Out of boundary → valid path
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;

        // No moves left
        if(move == 0) return 0;

        if(dp[i][j][move] != -1) return dp[i][j][move];

        int ans = 0;

        for(auto &[di, dj] : directions) {
            ans = (ans + solve(i + di, j + dj, move - 1)) % M;
        }

        return dp[i][j][move] = ans;
    }

    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        this->m = m;
        this->n = n;

        memset(dp, -1, sizeof(dp));

        return solve(sr, sc, maxMove);
    }
};