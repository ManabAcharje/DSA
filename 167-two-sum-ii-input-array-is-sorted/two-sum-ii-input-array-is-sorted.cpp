class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        int j = n-1;


        while(i<j){
            int curr = nums[i]+ nums[j];
            if(curr==target)return {i+1,j+1};
            else if(curr<target){
                i++;
            }else{
                j--;
            }
        }
        return {};

    }
};