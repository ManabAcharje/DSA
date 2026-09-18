class Solution {
public:
    unordered_map<int,int>dp;

    int longestSubsequence(vector<int>& arr, int diff) {
        
        int ans=1;
        for(int curr:arr){
            dp[curr]=dp[curr-diff]+1;

            ans=max(ans,dp[curr]);
        }
        return ans;
    }
};