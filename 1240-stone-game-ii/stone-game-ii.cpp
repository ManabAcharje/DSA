class Solution {
public:
    int n;
    int dp[101][101];
    vector<int> piles;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int remaining =
            piles[n - 1] -
            (i > 0 ? piles[i - 1] : 0);

        int ans = 0;

        for (int x = 1; x <= min(n - i, 2 * M); x++) {

            int opponent =
                solve(i + x, max(M, x));

            ans = max(ans,
                      remaining - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();
        this->piles = piles;

        // Prefix sum
        for (int i = 1; i < n; i++) {
            this->piles[i] += this->piles[i - 1];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};