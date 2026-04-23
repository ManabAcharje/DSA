class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans((int)nums.size(),0);
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int m = idx.size();

            
            vector<long long> pref(m, 0);
            pref[0] = idx[0];
            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + idx[i];
            }

            for (int j = 0; j < m; j++) 
            {
                long long left = 0, right = 0;

                if (j > 0)
                    left = (long long)j * idx[j] - pref[j - 1];

                if (j < m - 1)
                    right = (pref[m - 1] - pref[j]) - (long long)(m - j - 1) * idx[j];

                ans[idx[j]] = left + right;
            }
        }
            return ans;
    }
};