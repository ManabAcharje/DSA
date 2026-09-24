class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

     
        vector<int>diff(n+1,0);
        int active = 0;
        
        for(int i = 0; i<n;i++){
            
            active +=diff[i];
            int curr = nums[i]^(active & 1);
            if(curr == 1)continue;
            if(i+k>n)return -1;
            ans++;
            active++;
            diff[i+k]--;

           
        }
        return ans;
        
    }
};