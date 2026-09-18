class Solution {
public:
    vector<int> dp;

    bool winnerSquareGame(int n) {
        dp.assign(n+1,0);
        dp[0] = false;
        for(int x = 1 ; x <= n;x++){
            for(int i = 1 ; i*i <= x ; i++){
                if(dp[x-i*i]==false){
                    dp[x] = true;
                    break;
                }
            } 
        }
        return dp[n];
    }
};