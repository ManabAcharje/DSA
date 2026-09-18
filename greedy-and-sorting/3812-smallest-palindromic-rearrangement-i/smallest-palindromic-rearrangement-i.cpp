class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>freq(26, 0);
        int ans = 0;
        int i = 0;
        int j = n - 1;
        for (int ch : s) {
            freq[ch - 'a']++;
            ans ^= ch;
        }
        if (n & 1) {
            int mid = n / 2;
            s[mid] = ans;
        }
        if(!ans ==0)
        freq[ans-'a']-=1;
        int fi = 0;
        while (i < j) {
            while (freq[fi] == 0)
                fi++;
            s[i] = s[j] = fi + 'a';
            i++;
            j--;
            freq[fi]-=2;
        }
        return s;
    }
};