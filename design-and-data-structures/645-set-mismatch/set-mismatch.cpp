class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int total = (n*(1+n))/2;
        int duplicate;
        sort(nums.begin(),nums.end());
        int sum = nums[0];
        for(int i = 1 ; i< n ;i++){
            if(nums[i]==nums[i-1]){duplicate= nums[i];}
            sum +=nums[i];
        }

        int missing = total - (sum-duplicate);
        return {duplicate,missing};



    }
};