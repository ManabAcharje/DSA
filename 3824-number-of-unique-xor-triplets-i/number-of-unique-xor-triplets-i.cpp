class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int msb = 31 - __builtin_clz(n);
        if(n<=2)return n;
        return (1 << (msb + 1));
    }
};