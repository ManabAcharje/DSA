class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        map<int,int>freq;
        int k = k1 + k2;

        for(int i = 0; i<nums1.size(); i++){
            freq[abs(nums1[i]- nums2[i])]++;
        }
        while(k>0 && freq.rbegin()->first>0){
            auto it = prev(freq.end());
            int val = it->first ,count = it->second;
            freq.erase(it);
            int ops = min(k,count);
            freq[val-1] += ops;
            if(count>ops)freq[val] +=(count-ops);
            k-= ops;
        }

        for(auto const &[val,freq] : freq){
            ans += (long long ) val* val*freq;
        }
        
        return ans;
    }
};