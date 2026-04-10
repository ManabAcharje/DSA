class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){

            int sz=mp[nums[i]].size();
            if(sz>=2){
                int temp=2*(i-mp[nums[i]][sz-2]);
                ans=min(ans,temp);
            }
            mp[nums[i]].push_back(i);
            
        }
        // for(auto &[u,v]:mp){
        //     int sz=v.size();
        //     if(sz>=3){
        //         int temp=2*(v[2]-v[0]);
        //         ans=min(ans,temp);
        //     }
        // }
        return ans==INT_MAX?-1:ans;
    }
};