class Solution {
public:
    typedef long long ll;
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prev2, int prev1, bool tight , bool lz) {
        if (curr == n) {
            return {1, 0}; // no more score can be generated and we found one last number
        }

        if (!tight && !lz && prev2 >= 0 && prev1 >= 0) {
            if (dpTotalNumbers[curr][prev2][prev1] != -1) {
                return {dpTotalNumbers[curr][prev2][prev1], dpTotalWaviness[curr][prev2][prev1]};
            }
        }

        ll totalNumbers   = 0;
        ll totalWaveScore = 0;

        int limitDigit = tight ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newLz = lz && (digit == 0);

            int newPrev2 = prev1;
            int newPrev1     = newLz ? -1 : digit;

            auto [remainTotalNumbers, remainTotalWaveScore] = solve(
                curr + 1, newPrev2, newPrev1,
                tight && (digit == limitDigit),
                newLz
            );

            if (!newLz && prev2 >= 0 && prev1 >= 0) {
                bool isPeak   = (prev2 < prev1 && prev1 > digit);
                bool isValley = (prev2 > prev1 && prev1 < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }

            totalNumbers   += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!tight && !lz && prev2 >= 0 && prev1 >= 0) {
            dpTotalNumbers[curr][prev2][prev1]  = totalNumbers;
            dpTotalWaviness[curr][prev2][prev1] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if (num < 100) {
            return 0;
        }

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};
