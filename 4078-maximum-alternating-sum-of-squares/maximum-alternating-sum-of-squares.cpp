class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for(int &x : nums){
            if(x<0)x*=(-1);
            total += (long long) x *x;
        }
       
        sort(nums.begin(),nums.end());

        // 0 1 2 3 4 5 
        // 0 2 4 
        // 1 2 
        

        for(int i = 0 ; i<n/2; i++){
            
            total -= 2*((long long)abs(nums[i])*abs(nums[i]));
        }
        return total ; 
    }
};