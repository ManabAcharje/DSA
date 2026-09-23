class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        unordered_map<long long, int> mp;

        long long suff = nums[n - 1];
        int ans = n + 1;
        if(suff == x)ans = 1;
        int len = 1;
        mp[suff] = len;
        pref[0] = nums[0];


        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            suff += nums[n - i - 1];
            if(suff == x)ans = min(ans,i+1);
            mp[suff] = ++len;
        }

        // for(auto i : pref){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto it: mp){
        //     cout<<it.first<<"->"<<it.second<<endl;
        // }
        // cout<<endl;

      
        for (int i = 0; i < n; i++) {
            if (pref[i] == x) {
                ans = min(i + 1, ans);
                continue;
            }
            int y = x - pref[i];
            if (mp.count(y)&& mp[y] < (n-i)) {
                ans = min(ans, i + 1 + mp[y]);
            }
        }

        return ans >= n + 1 ? -1 : ans;
    }
};