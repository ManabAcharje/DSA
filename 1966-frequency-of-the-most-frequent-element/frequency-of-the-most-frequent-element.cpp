class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int j = 0;
        int i = 0;


        int  ans = 1;
        long long   curr = 0;
        int n = nums.size();

        for(int j = 0 ;j<n;j++){
            curr+=nums[j];
            if( curr + k >= (long long) (j-i+1)*nums[j]){
                ans = max(ans,(j-i+1));
            }
            else{
                while( i<j && curr+k < (j-i+1)*(long long) nums[j]){
                    curr-=nums[i];
                    i++;
                    
                }
            }
        }
        return ans;
    }
};