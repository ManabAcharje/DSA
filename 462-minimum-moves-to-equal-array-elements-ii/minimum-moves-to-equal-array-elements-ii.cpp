class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid;
        if(n&1){
            mid=nums[n/2];

        }
        else{
            mid=(nums[n/2]+nums[(n+1)/2])/2;
        }
        int ans=0;
        for(auto &num:nums){
            ans+=abs(mid-num);
        }
        return ans;

    }
};