class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=n-1;

        while(i<j && nums[i]==nums[i+1])i++;
        while(i<j && nums[j]==nums[j-1])j--;

        int result_idx=0;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]<nums[result_idx])result_idx=mid;
            if(nums[mid]>nums[j])i=mid+1;
            else j=mid-1;
        }
        return nums[result_idx];
        
    }
};