class Solution {
public:
    int  m;
    int  n;
    int  l;
    string s , t, u;

    int dp[101][101][201];
    bool solve(int i , int j ,int k){
        if (i == m && j == n &&  k == l){
            return true;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool opt1 = false;
        bool opt2 = false;
        
        if(i< m){
            if( s[i] == u[k]){
                opt1 = solve(i+1,j,k+1);
            }
        }
        if(j < n){
            if(t[j] == u[k]){
                opt2 = solve(i, j+1, k+1);
            }
        }
        return dp[i][j][k] = opt1 + opt2 ;



    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        l = s3.size();
        s = s1;
        t = s2;
        u = s3;

        if(m+ n != l )return false;
        memset(dp,-1,sizeof(dp));

        return solve(0,0,0);
    }  
};