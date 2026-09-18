const int Mod=1e9+7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            dp[i] =
                (dp[i]+(i >= one ? dp[i - one] : 0) + (i >= zero ? dp[i - zero] : 0))%Mod;
        }
        long long  ans = 0;
        for (int i = low; i <= high; i++) {
            ans =(ans+dp[i])%Mod;
        }
        return ans;
    }
};