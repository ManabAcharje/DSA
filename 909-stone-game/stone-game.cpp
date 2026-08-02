class Solution {
public:
    int n ;
    vector<int> nums;
    vector<vector<int>>dp;
    int solve(int i , int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int opt1  = nums[i]-solve(i+1,j);
        int opt2 = nums[j]- solve(i,j-1);
        return dp[i][j]=max(opt1, opt2);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        nums = piles;
        dp.assign(n,vector<int>(n,-1));
        int total = accumulate(piles.begin(),piles.end(),0);
        return solve(0,n-1)>=0;

    }
};