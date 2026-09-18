class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n, mx;
    vector<int> nums;
    vector<vector<vector<int>>> dp;

    int solve(int i, int g1, int g2) {
        if (i == n) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Option 1: Skip current element
        ans = solve(i + 1, g1, g2);

        // Option 2: Put current element in first subsequence
        int newG1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        ans = (ans + solve(i + 1, newG1, g2)) % MOD;

        // Option 3: Put current element in second subsequence
        int newG2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        ans = (ans + solve(i + 1, g1, newG2)) % MOD;

        return dp[i][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        mx = *max_element(nums.begin(), nums.end());

        dp.assign(
            n,
            vector<vector<int>>(mx + 1, vector<int>(mx + 1, -1))
        );

        return solve(0, 0, 0);
    }
};