class Solution {
public:
    vector<int> nums;
    string s;
    int n;
    long long  dp[100001][2];
    long long  solve(int i, int free) {

        if(i==n)return 0;
        if(dp[i][free]!=-1)return dp[i][free];

        if (s[i] == '0')
            return solve(i + 1, 1);

        else {
            long long  opt1 = 0; // move 1 to the right  edge case if i=0; so another
                          // state need be add for is idx is free or not;

            long long  opt2 = nums[i] + solve(i + 1, 0); //  don't move keep it there;
            if (i != 0 && free) {
                opt1 = nums[i - 1] + solve(i + 1, 1);
            }

            return dp[i][free]= max(opt1, opt2);
        }
    }
    long long maxTotal(vector<int>& nums, string s) {

        this->nums = nums;
        this->s = s;
        n = s.size();

        memset(dp,-1,sizeof(dp));

        return solve(0, 1);
    }
};