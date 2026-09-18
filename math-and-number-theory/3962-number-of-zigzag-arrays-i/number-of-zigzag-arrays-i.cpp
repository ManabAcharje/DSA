class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

       int dp[2001][2001][2];
        // Base case
        for (int v = 0; v < m; v++) {
            dp[n][v][0] = 1;
            dp[n][v][1] = 1;
        }

        for (int i = n - 1; i >= 1; i--) {

            vector<long long> pref0(m), pref1(m);

            pref0[0] = dp[i + 1][0][0];
            pref1[0] = dp[i + 1][0][1];

            for (int v = 1; v < m; v++) {
                pref0[v] = (pref0[v - 1] + dp[i + 1][v][0]) % MOD;
                pref1[v] = (pref1[v - 1] + dp[i + 1][v][1]) % MOD;
            }

            long long total0 = pref0[m - 1];
            long long total1 = pref1[m - 1];

            for (int v = 0; v < m; v++) {

                // next > current
                dp[i][v][0] =
                    (total1 - pref1[v] + MOD) % MOD;

                // next < current
                dp[i][v][1] =
                    (v == 0 ? 0 : pref0[v - 1]);
            }
            

        }

        long long ans = 0;

        for (int v = 0; v < m; v++) {
            ans = (ans + dp[1][v][0]) % MOD;
            ans = (ans + dp[1][v][1]) % MOD;
        }

        return (int)ans;
    }
};