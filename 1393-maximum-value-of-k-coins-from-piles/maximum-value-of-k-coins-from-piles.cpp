class Solution {
public:
    int n;
    int dp[1001][2001];
    
    int solve(int p ,int k,vector<vector<int>>& piles){

        if(p==n || k==0)return 0;

        if(dp[p][k]!=-1)return dp[p][k];

        int ans=solve(p+1,k,piles);
        int m=piles[p].size();
        for(int i=0;i<min(m,k);i++){
            int temp=piles[p][i]+solve(p+1,k-i-1,piles);
            ans=max(temp,ans);
        }
        return dp[p][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        
        for(auto &pile:piles)
        {
            int m=pile.size();
            for(int i=1;i<m;i++)
            {
                pile[i]+=pile[i-1];
            }
        }
        return solve(0,k,piles);
        
    }
};