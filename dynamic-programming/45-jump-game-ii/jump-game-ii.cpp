class Solution {
public:
    int n;
    int dp[10001];
    long long solve(int i,vector<int>&nums ){
        
        if(i==n-1)return 0;
        if(i>=n)return INT_MAX;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            int s=solve(i+j,nums);
            if(s==INT_MAX){
                continue;
            }
            
            ans=min(ans,1+s);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};