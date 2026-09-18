class Solution {
public:
    vector<int>memo;
    int n;
    int solve(int i,string&s) {
        if (i == n)
            return 1;


        if(s[i]=='0')return 0;

        if(memo[i]!=-1)return memo[i];

        int ans=solve(i+1,s);
        if(i+1<n){
            int num= (s[i]-'0')*10+s[i+1]-'0';
            if(num>=10 && num<=26){
                ans+=solve(i+2,s);
            }
        }
        return memo[i]=ans;
    }
    int numDecodings(string s) {
        n = s.size();
        memo.resize(n+1,-1);
        // 2,2,6
        // 22,6
        // 2,26
        // 226 so i need to do is this
        // dp
        // how keep

        //           2
        //     2 2           22
        // 2 2 6 2 26      22 6   226
        return solve(0,s);
    }
};