class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(int i , int j , string &s, string &t){

        if(j==n)return 1;
        if(i==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int not_take = solve(i+1,j,s,t);
        int take =0;
        if(s[i]==t[j]){
            take = solve(i+1,j+1,s,t);
        }
        return dp[i][j] = take+not_take;
    }
    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};