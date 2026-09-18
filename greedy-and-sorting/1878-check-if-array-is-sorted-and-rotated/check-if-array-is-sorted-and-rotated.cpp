class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i;
        
        if(n==1)return true;
        bool flag=false;
        for(i=1;i<n;i++){
            if(nums[i-1]>nums[i]){break;flag=true;}
            
        }
        if(i==n)return true;
        
        for(int j=i;j<n-1;j++){
            if(nums[j]>nums[j+1] || nums[j]>nums[0])return false;
        }
       return nums[n-1]<=nums[0];
    }
};