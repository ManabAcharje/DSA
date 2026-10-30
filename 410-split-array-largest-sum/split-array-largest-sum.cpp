class Solution {
public:
    int n;
    int dp[1001][51];
    int solve(vector<int> &pref,int idx ,  int k){
        if(k == 1 ){
           return (idx > 0) ? pref[n-1] - pref[idx- 1] : pref[n-1];
        }
        if (dp[idx][k] != -1)return dp[idx][k];
        int ans = INT_MAX;
        for(int i = idx ; i <= n - k ; i++){
            int  temp = max ((idx > 0) ? pref[i] - pref[idx-1] : pref[i],solve(pref, i + 1 , k - 1));
            ans = min(temp ,ans);
        }
        return dp[idx][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        n  = nums.size();
        memset(dp,-1,sizeof(dp));
        vector<int>pref(n,0);
        pref[0]  =  nums[0];
        for(int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] +  nums[i];
        }
        return solve(pref,0,k);
    }
};
// 1 3 6 10 15