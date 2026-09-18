class Solution {
public:
    string s, t;
    int m, n;
    unordered_map<long long ,int>memo;

    long long solve(int i, int j) {
        if (j == m)
            return 1;

        if (i == n)
            return 0;
        

        long long  key = ((long long)i<<32)|j;

        if (memo.count(key))
            return memo[key];

        if (s[i] == t[j]) {
            return memo[key] = solve(i + 1, j + 1) + solve(i + 1, j);
        }

        return memo[key] = solve(i + 1, j);
    }

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;

        n = s.size();
        m = t.size();

        

        if (n < m)
            return 0;

        return solve(0, 0);
    }
};