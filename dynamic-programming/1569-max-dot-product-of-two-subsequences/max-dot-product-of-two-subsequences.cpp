class Solution {
public:
    int n, m;

    vector<vector<int>> dp;
    vector<int> nums1, nums2;

    int solve(int i, int j) {

        if (i == n || j == m)
            return -1e9;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int next = solve(i + 1, j + 1);

        int takeBoth = nums1[i] * nums2[j] +
                       max(0, next);

        int skip1 = solve(i + 1, j);

        int skip2 = solve(i, j + 1);

        return dp[i][j] =
            max({takeBoth, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1,
                      vector<int>& nums2) {

        n = nums1.size();
        m = nums2.size();

        dp.assign(n, vector<int>(m, INT_MIN));

        this->nums1 = nums1;
        this->nums2 = nums2;

        return solve(0, 0);
    }
};