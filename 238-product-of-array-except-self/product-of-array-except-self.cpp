class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //curr multiplication will be prefix * suffix   

        int n= nums.size();
        vector<int> ans(n,1);
        // ans[0] =  1

    //     0 1 2 3 
    // ans-1 1 1 1
    //     1 2 3 4  

    //     1 1*1  1*2 2*3
        
        for(int i = 1 ; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        // 1 1*1 2*1 3*2
        // 1  1   2   6 
        int suff_mul = 1;
        for(int i= n-2;  i>=0;i--){
            suff_mul*= nums[i+1];

            ans[i]*=suff_mul;

        }
      
        return ans;

    }
};