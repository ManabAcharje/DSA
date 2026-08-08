class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        int  n = nums.size();

        for(int i = 1 ; i < n; i++ ){
            if(nums[i]==major){
                count++;

            }
            else if(nums[i]!=major){
                count--;
                if(count == -1 ){
                    major = nums[i];
                    count = 1;
                }
            }
        }
        return major;
    }
};