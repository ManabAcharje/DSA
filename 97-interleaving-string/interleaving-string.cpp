class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[101][101][201] = {0};
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        if (m + n != l)
            return false;
        dp[m][n][l] = 1;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                for (int k = l; k >= 0; k--) {
                    if (i == m && j == n && k == l) {
                        continue;
                    }

                    bool opt1 = false;
                    bool opt2 = false;
                    if (i < m && k < l) {
                        if (s1[i] == s3[k]) {
                            opt1 = dp[i + 1][j][k + 1];
                        }
                    }

                    if (j < n && k < l) {
                        if (s2[j] == s3[k]) {
                            opt2 = dp[i][j + 1][k + 1];
                        }
                    }
                    dp[i][j][k] = opt1 | opt2;
                }
            }
        }
        return dp[0][0][0];
    }
};