class Solution {
public:
    unordered_set<string>st;
    int n;
    vector<int>dp;



    bool  solve(int i , string &s){
        if(i==n)return true;

        if(dp[i]!=-1)return dp[i];
        
        for(int j = i ; j < n ; j++)
        {
            if(st.count(s.substr(i,j-i+1))){
                bool found_right=solve(j+1,s);
                if(found_right==true)return true;
            }
        }
        return dp[i]=false;

    }

    
    bool wordBreak(string s, vector<string>& wordDict) {

        n=s.size();
        dp.assign(n+1,-1);

        for(auto &word:wordDict){
            st.insert(word);
        }
        return solve(0,s);




    }
};

/*
    leetcode 
    l  solve("eetcode")
    le + solv("etcode")
    .................
    ..............
    leet + solve("code")---> here we found substring (0, 3) && solve "code" so can return true; 
    else return false;
*/