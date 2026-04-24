class Solution {
public:
    int n;
    string s;
    unordered_set<string> dict;
    vector<int> dp;

    int solve(int i) {
        if(i>=n)return 0;
        
        if(dp[i]!=-1)return dp[i];

        int ans=1+solve(i+1);//considering ith char as extra;
        string temp="";
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(dict.count(temp)){
                ans=min(ans,solve(j+1));
            }
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        this->s = s;
        this->n = s.size();
        dp.assign(n, -1);

        for (auto &w : dictionary) {
            dict.insert(w);
        }

        return solve(0);
    }
};