class Solution {
public:
    int dp[501][501];
    int n;
    int solve(int i,int t,vector<int>& satisfaction){
        // base condition
        if(i>=n)return 0;
        if(dp[i][t]!=-1)return dp[i][t];

        // i have two option 
        int pick=(t)*satisfaction[i]+solve(i+1,t+1,satisfaction);
        int not_pick=solve(i+1,t,satisfaction);


        return dp[i][t]=max(pick,not_pick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        // so i have choices to pick dises;
        memset(dp,-1,sizeof(dp));
        sort(satisfaction.begin(),satisfaction.end());
        n=satisfaction.size();
        return solve(0,1,satisfaction);
    }
};