class Solution {
public:
    // max 1 absence;
    // consecutive late for 2days;
    // total possibilities= 3*3*3....n times  
    const int Mod=1e9+7;
    // 
    int n;
    int dp[100001][2][3];
    int solve(int i, int absence, int late ){
        if(i==n)return 1;
        if(dp[i][absence][late]!=-1)return dp[i][absence][late];
        
        long long total=solve(i+1,absence,0)%Mod;

        if(absence<1)total=(total +solve (i+1,absence+1,0))%Mod;
        if(late<2)total   =(total +solve (i+1,absence,late+1))%Mod;

        return dp[i][absence][late]=total;
    }
    int checkRecord(int n) {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
        
    }
};