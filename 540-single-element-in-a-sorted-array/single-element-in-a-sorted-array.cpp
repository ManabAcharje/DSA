class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr= 0;
        for(int x : nums){
            xorr= xorr^x;

        }
        return xorr;
    }
};