class Solution {
public:
    int minStartValue(vector<int>& nums) {
       // start val always grater than 0 ;
        // 4 because -3 +2  -3 +4 +2 min value reached is -4 (x+(-4)= 1-(mini))

        int mini= nums[0];
        for(int i=1; i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
            mini=min(mini,nums[i]);

        } 
        return (mini>=1)?1:1-(mini);
    }
};