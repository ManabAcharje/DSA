class Solution {
public:
    vector<int> dp;
    bool solve(int n ){
        if(n==0)return false;

        if(dp[n]!=-1)return dp[n];
        bool ans = false;
        for(int i=1; i*i<=n;i++){
            bool temp = solve(n-i*i);
            if(temp == false){
                ans=true;
                break;
            }
        }
        return dp[n] = ans;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return  solve(n);
    }
};