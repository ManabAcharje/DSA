class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans+=(count-1)/2;
                count=0;
            }
            else{
                count++;
            }
        }
        ans+=(count)/2;
        if(ans>=n)return true;
        return false;
    }
};