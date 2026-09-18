class Solution {
public:
    int n;
    int mod = 1e9+7;
    int dp[1001][1001];
    
    int solve(int i,int k){

        if(k==0)return 1;

        if(i>=n-1)return 0;

        if(dp[i][k]!=-1)return dp[i][k];
        int skip = solve(i+1,k)%mod;
        int take = 0;
        for(int j = i+1 ; j<n;j++){
            if(dp[j][k-1]!=-1){
                take = (take + dp[j][k-1] %mod)%mod;
            }
            else {
                dp[j][k-1] = solve(j,k-1);
                take = (take +  dp[j][k-1]%mod)%mod;
            }
        }
        return dp[i][k]= (take + skip)%mod;

    }
    int numberOfSets(int n, int k) {
        this->n = n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k);
    }
};