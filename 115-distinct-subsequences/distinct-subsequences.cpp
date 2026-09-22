class Solution {
public:
    // int m,n;
    // int dp[1001][1001];
    // int solve(int i , int j , string &s, string &t){

    //     if(j==n)return 1;
    //     if(i==m)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int not_take = solve(i+1,j,s,t);
    //     int take =0;
    //     if(s[i]==t[j]){
    //         take = solve(i+1,j+1,s,t);
    //     }
    //     return dp[i][j] = take+not_take;
    // }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned int>>dp(m+1,vector<unsigned int>(n+1,0));
        
        for(int i = 0; i<=m;i++){
            dp[i][n] = 1;
        }

        for(int  i = m-1; i>=0; i--){
            for(int j  = 0 ;j<n  ; j++){
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};