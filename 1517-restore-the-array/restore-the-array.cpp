class Solution {
public:
    const int Mod=1e9+7;
    vector<int>dp;
    int n;
    int solve(int i, int k, string &s){
         if(i==n)return 1;
        
        
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        long long num=0;
        long long ans=0;

    
        for(int j=i;j<n;j++){
            num=num*10+(s[j]-'0');
            if(num>=1 && num<=k){
                ans=(ans+solve(j+1,k,s))%Mod;
            }
            else{
                break;
            }

         }
         return dp[i]=ans;

    }
    int numberOfArrays(string s, int k) {
        n=s.size();
        dp.assign(n+1,-1);
        return solve(0,k,s);
    }
};