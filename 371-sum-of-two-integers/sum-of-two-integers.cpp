class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int bit1 = (a >> i) & 1;
            int bit2 = (b >> i) & 1;

            int currentBit = bit1 ^ bit2 ^ carry;

            sum |= (currentBit << i);
            carry = (bit1 & bit2) | (bit2 & carry) | (bit1 & carry);
        }

        return sum;
    }
};