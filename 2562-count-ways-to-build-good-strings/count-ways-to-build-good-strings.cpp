class Solution {
public:
    const int M=1e9+7;
    int dp[1000001];
    int one;
    int zero;
    int high;
    int low;
    int solve(int l) {
        bool in_range=false;
        if(dp[l]!=-1)return dp[l];
        if (l > high)
            return 0;
        
        else if (l < low) {

        }
        else {
            in_range=true;
        }
        int opt1 = solve(l+one)%M;
        int opt2 = solve(l+zero)%M;
       

        return dp[l]= in_range +(opt1 + opt2)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        this->one = one;
        this->zero = zero;
        this->high = high;
        this->low = low;
        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};