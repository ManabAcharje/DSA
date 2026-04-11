class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int curr_count=0;
        int prev_count=0;

        bool has_zero=false;

        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)curr_count++;
            else{
                has_zero=true;
                result=max(curr_count+prev_count,result);
                prev_count=curr_count;
                curr_count=0;


            }
        }
        result = max(result,curr_count+prev_count);
        return has_zero?result:result-1;


        
    }
};