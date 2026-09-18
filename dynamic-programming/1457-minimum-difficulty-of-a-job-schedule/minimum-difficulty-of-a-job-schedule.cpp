class Solution {
public:
    int dp[301][11];
    int solve(vector<int>&jd,int i,int n,int d){
        if(d==1){
            int maxi = INT_MIN;
            for(int k=i;k<n;k++){
                maxi=max(maxi,jd[k]);

            }
            return maxi;
        }
        if(dp[i][d]!=-1)return dp[i][d];
        int ans=INT_MAX;
        int max_num=INT_MIN;
        for(int k=i;k<=n-d;k++){
            max_num=max(max_num,jd[k]);
            int temp=max_num+solve(jd,k+1,n,d-1);
            ans=min(temp,ans);
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();


        if(n<d)return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jd,0,n,d);
    }
};