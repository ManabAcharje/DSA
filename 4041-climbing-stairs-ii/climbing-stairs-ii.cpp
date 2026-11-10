class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,0);
        if(n==0)return 0;
        dp[0] = 0;
        if(n>=1)
            dp[1] = dp[0] + costs[0] + 1;
        if(n>=2)
            dp[2] = min(dp[1] + costs[1] + 1 , 4 + costs[1]);

        // cout<<dp[0] << " "<<dp[1] << " "<<dp[2]<<endl;
        // return  0;
        for(int i= 3 ; i<= n ; i++){
            dp[i] =min(dp[i-1] + 1,min(dp[i-2] + 4,dp[i-3] + 9)) + costs[i-1] ;
        } 
        for(int i = 0 ; i <= n ;i++){
            cout<<dp[i] <<" ";
        }
        return dp[n];
    }
};