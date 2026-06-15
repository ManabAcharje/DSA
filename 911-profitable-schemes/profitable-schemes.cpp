class Solution {
public:
    const int MOD = 1e9 + 7;

    int n, minProfit;
    vector<int> group, profit;

    int dp[101][101][101];

    int solve(int i, int members, int prof) {
        if (i == group.size())
            return prof >= minProfit;

        if(dp[i][members][prof]!=-1)return dp[i][members][prof];

        long long res = solve(i + 1, members, prof);

        if (members + group[i] <= n) {
            res += solve(
                i + 1,
                members + group[i],
                min(minProfit, prof + profit[i])
            );
        }

        return dp[i][members][prof] = res % MOD;
    }

    int profitableSchemes(
        int n,
        int minProfit,
        vector<int>& group,
        vector<int>& profit
    ) {
        this->n = n;
        this->minProfit = minProfit;
        this->group = group;
        this->profit = profit;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};