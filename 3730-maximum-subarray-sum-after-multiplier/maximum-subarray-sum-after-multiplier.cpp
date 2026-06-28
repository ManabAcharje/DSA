class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        // num is no part of anything
        // num is a part of the mul
        // num is a part of div
        // num is after the end
        long long neg = -((long long )1 <<60);

        long long dp0 = 1LL*nums[0];
        long long dp1 = 1LL*nums[0] * k;
        long long dp2 = 1LL*nums[0] / k;
        long long dp3 = neg;

       

        long long ans = max({dp1,dp2});

        for (int i = 1; i < nums.size(); i++) {
            long long num = nums[i];
            long long mul = num * k;
            long long div = num / k;

            long long ndp0 = max(num, dp0 + num);
            long long ndp1 = max({mul, dp0 + mul, dp1 + mul});
            long long ndp2 = max({div, dp0 + div, dp2 + div});
            long long ndp3 = max({num, dp3 + num, dp1 + num, dp2 + num});

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;
            dp3 = ndp3;

            ans = max({ans, dp0, dp1, dp2, dp3});
        }
        return ans;
    }
};