class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            mp[0] = 1;
            int sum = 0;
            for (int j = i; j < n; j++) {
                mp[(-2*nums[j]) % k] = 1;
                sum += nums[j];
                int mod_sum = sum % k;
                
                if(mp.count(k - mod_sum))
                    len = max(len ,j-i+1);
                else if(mp.count(- k - mod_sum))
                    len = max(len,j-i+1);
                else if(mp.count(-mod_sum))
                     len = max(len , j-i+1);
            }
        }
        return len;
    }
};