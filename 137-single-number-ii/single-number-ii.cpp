class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int bitmod = 0;

            for (int num : nums) {
                bitmod = (bitmod + ((num >> i) & 1)) % 3;
            }

            if (bitmod != 0) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};