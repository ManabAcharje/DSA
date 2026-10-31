class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        // reverse(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());
        vector<int> v(nums.size());
        for(int i = 0 ; i< nums.size() ; i++){
            v[(i+k)%nums.size()] = nums[i];
        }
        for(int i = 0 ; i < nums.size() ;i++){
            nums[i]  = v[i];
        }



    }
};