class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums(n);
        ugly_nums[0] = 1;

        int a = 0, b = 0, c = 0;

        for (int i = 1; i < n; i++) {
            int next2 = ugly_nums[a] * 2;
            int next3 = ugly_nums[b] * 3;
            int next5 = ugly_nums[c] * 5;

            ugly_nums[i] = min({next2, next3, next5});

            if (ugly_nums[i] == next2) a++;
            if (ugly_nums[i] == next3) b++;
            if (ugly_nums[i] == next5) c++;
        }

        return ugly_nums[n - 1];
    }
};