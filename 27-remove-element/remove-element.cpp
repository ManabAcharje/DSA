class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = n - 1 ; 
        int i = 0;
        for(i = 0 ; i< n; i++){
            while(j >= 0 && nums[j] == val)j--;
            if(i >=( j+1) )break;
            if(nums[i] == val){
                swap (nums[i],nums[j]);
            } 


        }
        return i ;
    }
};