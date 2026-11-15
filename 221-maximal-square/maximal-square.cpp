class Solution {
public:
    int ans = 0;
    int n, m;

    int dp[301][301];
    int solve(int i, int j , vector<vector<char>>&mat) {
        if (i == m - 1 || j == n - 1)
            return 1;

        if(dp[i][j]!=-1)return dp[i][j];
        int right = 0 ;
        if(j+1 < n && mat[i][j+1]== '1'){
            right = solve(i,j+1,mat);
        }
        int diag  = 0  ;
        if(i + 1 < m && j + 1 < n  && mat[i+1][j+1] == '1'){
            diag = solve(i+1,j + 1, mat);
        }
        int down  = 0 ;
        if(i + 1 < m && mat[i+1][j] == '1'){
            down = solve(i+1,j,mat);
        }
    return dp[i][j]=1 + min({right , diag , down});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    int temp = solve(i, j,matrix);
                    ans = max(temp, ans);
                }
            }
        }
        return ans * ans;
    }
};