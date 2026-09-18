class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int f=0;int sum=0;
        for(int i=0;i<n;i++){
            f+=i*nums[i];
            sum+=nums[i];
        }
        int ans=f;
        for(int k=1;k<n;k++){
            f=f+sum-(nums[n-k]*n);
            ans=max(ans,f);
        }
        return ans;
    }
};