class Solution {
public:
    // int m, n;
    // string s, t;

    // // int dp[1001][1001];
    // // int solve(int i, int j) {
    // //     if (i == m || j == n)
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == t[j]) {

    //         return dp[i][j] = 1 + solve(i + 1, j + 1);

    //     } else {
    //         return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
    //     }
    // }

    int longestCommonSubsequence(string s, string t) {
       int m =  s.size();
       int n = t.size();

        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            dp[i][n]=0;
        }
        for(int j = 0; j<n;j++){
            dp[m][j]=0;
        }

        for(int i =m -1; i>=0;i--){
            for(int j = n-1; j>=0 ;j--){
                if(s[i]==t[j]){
                    dp[i][j]= 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];

    }
};