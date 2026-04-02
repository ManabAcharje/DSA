class Solution {
public:
    int n;
    int dp[1000001][2];
    int solve(int i,int prev,string &s){
        if(i==n)return 0;

        int flip=INT_MAX;
        int not_flip=INT_MAX;
        if(dp[i][prev]!=-1)return dp[i][prev];

        if(s[i]=='0')
        {   

            if(prev==0){
                not_flip=solve(i+1,0,s);
                flip=1+solve(i+1,1,s);
            }
            else{
                //prev==1
                flip=1+solve(i+1,1,s);
            }
            
            
        }
        else if(s[i]=='1'){
            if(prev==0){
                not_flip=solve(i+1,1,s);
                flip=1+solve(i+1,0,s);

            }
            else{
                //prev=1;
                not_flip=solve(i+1,1,s);

            }

        }
        return  dp[i][prev]=min(flip,not_flip);
    }
    int minFlipsMonoIncr(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};