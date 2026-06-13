class Solution {
public:
    int dp[1001][1001];
    int longestArithSeqLength(vector<int>& nums) {
        int ans=2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+500;
                dp[i][diff]= dp[j][diff]>0?dp[j][diff]+1:2;
                ans=max(ans,dp[i][diff]);
            }

        }
        return ans;

    }
};