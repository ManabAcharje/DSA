
class Solution {
public:
    int reverse8Bits(int x) {
        int rev = 0;

        for (int i = 0; i < 8; i++) {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }

        return rev;
    }

    bool check(int x) {
        bitset<8> bits(x);

        int i = 0;
        int j = 7;

        while (i < j) {
            if (bits[i] != bits[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    bool isPalindromic(string s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        // Check middle character if length is odd
        if (n & 1) {
            int x = s[n / 2];
            
            if (!check(x))
                return false;
        }

        while (i < j) {
            int x = s[i];
            int y = s[j];

            int rev = reverse8Bits(x);

            if (rev != y)
                return false;

            i++;
            j--;
        }

        return true;
    }
};
/*
    co
*/