class Solution {
public:
    int n;
    vector<int>palin_len;
    vector<int>dp;
    void f(string &s, int k){
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i = 0; i<n;i++){
            dp[i][i]  = true;
        }

        for(int len = 2 ; len <=n; len++){
            for(int i = 0 ;i+len <= n;i++){
                int j = i+len-1;
                dp[i][j] = (s[i]==s[j]);
                if(len>2){
                    dp[i][j] = dp[i][j] & dp[i+1][j-1];
                }
            }
        }
        for(int i = 0; i<n;i++){
            for(int  j = i+k-1;j<n;j++){
                if(dp[i][j]){
                    palin_len[i] = j-i+1;
                    break;
                }
            }
        }
        return ;
        

       
    }
    int fun(int i, string& s, int k) {
        if(palin_len[i]>=k)return palin_len[i];
        else return 0;   

    }
    int solve(int i, string& s, int k) {
        // cout<<"for i = : "<<i<<endl;
        if (i > n - k)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int res = fun(i,s,k);
        // cout<<"res = "<<res<<endl;



        int take = INT_MIN;
        if(res>=k) take =1 +  solve(i+res,s,k);
        int not_take = solve(i + 1, s, k);

        // cout<<"take = "<<take<<" and not_take "<<not_take<<endl;

        return dp[i] = max(take, not_take);
    }
    int maxPalindromes(string s, int k) {
        
        n = s.size(); 
        dp.resize(n,-1);

        if(k==1)return n;
        palin_len.resize(n,1);
        f(s,k);
        // for(int  i = 0 ;i<n;i++){
        //     // cout<<"palin_len[i] "<<palin_len[i]<<endl;

        // }
        // cout<<"________________________________"<<endl;
        return solve(0, s, k);
    }
};