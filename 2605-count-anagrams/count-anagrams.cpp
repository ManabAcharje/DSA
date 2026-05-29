class Solution {
public:
    const int Mod = 1e9 + 7;
    vector<long long> fact;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % Mod;
            }
            a = (a * a) % Mod;
            b >>= 1;
        }
        return res;
    }
    void buildFactorials(int n) {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % Mod;
        }
    }
    int countAnagrams(string s) {
        buildFactorials(s.size());
        stringstream ss(s);
        string word;
        long long ans = 1;
        while (ss >> word) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            long long ways = fact[word.size()];
            for (int f : freq) {
                if (f > 1) {
                    ways = (ways * power(fact[f], Mod - 2)) % Mod;
                }
            }
            ans = (ans * ways) % Mod;
        }
        return ans;
    }
};