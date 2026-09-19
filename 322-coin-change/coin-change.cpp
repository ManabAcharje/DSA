class Solution {
public:
    int n ;
    vector<int>coins;
    vector<vector<long long >> dp;
    long long  solve(int i , int target){
        if(target == 0)return 0;

        if(i<0)return INT_MAX;
        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        long long  take = INT_MAX;
        if(target>=coins[i]){
            take = 1 + min(solve(i-1,target-coins[i]), solve(i,target-coins[i]));
        }
        long long  not_take = solve(i-1,target);

        return dp[i][target] = min(take,not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        n = coins.size();
        this->coins = coins;
        dp.resize(n+1,vector<long long>(amount+1,-1));
        return solve(n-1,amount)==INT_MAX?-1: (int)solve(n-1,amount);

        
    }
};