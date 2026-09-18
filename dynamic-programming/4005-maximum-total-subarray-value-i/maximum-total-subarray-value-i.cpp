class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        long long  maxi=*max_element(nums.begin(),nums.end());
        long long  mini=*min_element(nums.begin(),nums.end());

        return (maxi-mini)>=LLONG_MAX/k?LLONG_MAX: k*(maxi-mini);
    }
};