class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_res = 0;
        for(int x: nums){
            xor_res^= x;


            
        }
        if(xor_res != 0)return n;
        bool all_zero = false;
        sort(nums.begin(),nums.end());
        if(nums.back()==0)all_zero = true;
        return all_zero?0: n - 1;


        
    }
};