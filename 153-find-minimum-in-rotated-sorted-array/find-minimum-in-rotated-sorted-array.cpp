class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;

        if(nums[low]<=nums[high])return nums[0];
        int mini=INT_MAX;

        while(high>=low){
            int mid=low+(high-low)/2;
            mini=min(nums[mid],mini);
            // identify the sorted portion
            if(nums[mid]>=nums[low]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                high=mid-1;
                mini=min(mini,nums[mid+1]);
                }
        }       
        return mini;
    
    }
};