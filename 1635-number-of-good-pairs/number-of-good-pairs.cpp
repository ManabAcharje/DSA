class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[nums[0]]++;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};