class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long dp0 = LONG_MIN; // 0 deletions , ending with +ve
        long long dp1 = LONG_MIN; // 0 deletions ,ending with -ve
        long long dp2 = LONG_MIN; // 1 deletions, ending with +ve;
        long long dp3 = LONG_MIN; // 1 deletions , ending with -ve;

        long long ans = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            long long curr = nums[i];

            long long n0 = max(dp1 == LONG_MIN ? LONG_MIN : dp1 + curr, curr);
            long long n1 = dp0 == LONG_MIN ? LONG_MIN : dp0 - curr;
            long long n2 = max(dp0, dp3 == LONG_MIN ? LONG_MIN : dp3 + curr);
            long long n3 = max(dp1, dp2 == LONG_MIN ? LONG_MIN : dp2 - curr);

            // cout << "for i = : " << i << endl;
            // cout << n0 << " " << n1 << " " << n2 << " " << n3 << endl;

            ans = max({ans,n0, n1, n2, n3});
            dp0 = n0;
            dp1 = n1;
            dp2 = n2;
            dp3 = n3;
        }
        return ans;
    }
};