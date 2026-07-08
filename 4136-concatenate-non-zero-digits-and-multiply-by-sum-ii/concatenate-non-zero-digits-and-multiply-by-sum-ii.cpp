class Solution {
public:
    static const int Mod = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefSum(n);
        vector<long long> prefNum(n);
        vector<int> nonZeroCnt(n);
        vector<long long> pow10(n + 1, 1);

        prefSum[0] = s[0] - '0';
        nonZeroCnt[0] = (s[0] != '0');

        if (s[0] != '0')
            prefNum[0] = s[0] - '0';
        else
            prefNum[0] = 0;

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % Mod;

        for (int i = 1; i < n; i++) {
            int d = s[i] - '0';

            prefSum[i] = prefSum[i - 1] + d;
            nonZeroCnt[i] = nonZeroCnt[i - 1] + (d != 0);

            if (d == 0)
                prefNum[i] = prefNum[i - 1];
            else
                prefNum[i] = (prefNum[i - 1] * 10 + d) % Mod;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long digitSum = prefSum[r] - (l ? prefSum[l - 1] : 0);

            int k = nonZeroCnt[r] - (l ? nonZeroCnt[l - 1] : 0);

            long long num;
            if (l == 0) {
                num = prefNum[r];
            } else {
                num = (prefNum[r]
                      - prefNum[l - 1] * pow10[k] % Mod
                      + Mod) % Mod;
            }

            ans.push_back((digitSum * num) % Mod);
        }

        return ans;
    }
};