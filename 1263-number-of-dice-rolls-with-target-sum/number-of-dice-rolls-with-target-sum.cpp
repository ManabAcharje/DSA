class Solution {
public:
    const int Mod=1e9+7;
    int k,target,n;
    int dp[31][1001];
    int solve(int i,int curr){
        if(i==n && curr ==target)return 1;
        if(i!=n && curr>=target )return 0;
        if(i>=n && curr<target)return 0;

        if(dp[i][curr]!=-1)return dp[i][curr];

        int ans=0;
        for(int x=1;x<=k;x++){
            ans=(ans+solve(i+1,curr+x))%Mod;
        }

        return dp[i][curr]=ans;

    }
    int numRollsToTarget(int n, int k, int target) {
        //this is a clear dp problem  
        //define states i->dice no
        // i have to use all dices 
        this->target=target;
        this->k=k;
        this->n=n;
        memset(dp,-1,sizeof(dp));


        return solve(0,0);

    }
};