class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i ,int prev_idx, vector<int> &nums){
        if(i==n)return 0;
        if(dp[i][prev_idx+1]!=-1)return dp[i][prev_idx+1];
        int not_pick = solve(i+1,prev_idx,nums);
        int pick = -1;
        if(prev_idx == -1 || nums[i]>nums[prev_idx]){
            pick = 1 + solve(i+1,i,nums);

        }
        return dp[i][prev_idx +1] = max(pick,not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};