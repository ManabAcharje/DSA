class Solution {
public:
    int m,n;
    string s,t;

    int dp[1001][1001];
    int solve(int i, int j){
        if( i== m || j == n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){

            
            return dp[i][j]=1 + solve(i+1,j+1);



        }
        else{
            return dp[i][j]=max(solve(i+1,j), solve(i,j+1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        s= text1;
        t= text2;
        m = text1.size();
        n = text2.size();

        memset(dp, -1, sizeof(dp));

        return solve(0,0); 
    }
};