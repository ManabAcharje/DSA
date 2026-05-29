class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    void build(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    int countAnagrams(string s) {

        build(s.size());

        stringstream ss(s);
        string word;

        long long answer = 1;

        while (ss >> word) {

            sort(word.begin(), word.end());

            int n = word.size();

            long long ways = 1;

            int len = 1;

            for (int i = 1; i <= n; i++) {

                if (i < n && word[i] == word[i - 1]) {
                    len++;
                } else {

                    ways = (ways * invFact[len]) % MOD;
                    len = 1;
                }
            }

            ways = (ways * fact[n]) % MOD;

            answer = (answer * ways) % MOD;
        }

        return answer;
    }
};