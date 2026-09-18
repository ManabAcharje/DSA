class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int i,int j, string &s,string &t){
        // base condn
        if(i==n|| j==n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        int not_take=0;

        if(s[i]==t[j]){
            take=1+solve(i+1,j+1,s,t);
           
        }
        
         not_take=max(solve(i+1,j,s,t),solve(i,j+1,s,t));
         return dp[i][j]=max(take,not_take);
    }
    int lcs(string &s,string &t){
        return solve(0,0,s,t);
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        string t=s;
        reverse(s.begin(),s.end());
       
        return lcs(s,t);

    }
};