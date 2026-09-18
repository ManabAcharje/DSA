class Solution {
public:
    int n;
    vector<int> nums;
    vector<int> dp;

    int solve(int i) {
        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int ans = nums[i] - solve(i + 1);

        if (i + 1 < n)
            ans = max(ans, nums[i] + nums[i + 1] - solve(i + 2));

        if (i + 2 < n)
            ans = max(ans, nums[i] + nums[i + 1] + nums[i + 2] - solve(i + 3));

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        nums = stoneValue;
        n = nums.size();

        dp.assign(n, INT_MIN);

        int res = solve(0);

        if (res > 0)
            return "Alice";
        if (res < 0)
            return "Bob";
        return "Tie";
    }
};