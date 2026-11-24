class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long > pref(n, 0), suff(n, 0);
        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                pref[i] = pref[i - 1] + 1;

            } else {
                pref[i] = 1;
            }
            // cout << nums[n - 1 - i] << " " << nums[n - i];
            // cout << endl;long long 
            if (nums[n - i - 1] == nums[n - i]) {
                suff[n - i - 1] = suff[n-i]+ 1;
            } else {
                suff[n - i - 1] = 1;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << pref[i] << " ";
        // }
        // cout << endl;
        // for (int s : suff) {
        //     cout << s << " ";
        // }
        long long  min_opt = LLONG_MAX;
        for(long long  i = 1 ; i< n - 1 ; i++){
            long long  curr= 0;
            if(nums[i] == nums[i+1]){
                long long  r =  suff[i+1];
                curr = curr + nums[i]*(n-1 - i - r);

            }else{
                curr = curr + nums[i]*(n-i-1);
            }
            // cout<<curr<<"  ";
            if(nums[i] == nums[i-1]){
                curr = curr + nums[i]*(i - pref[i-1]);
            }else{
                curr = curr + nums[i]*i;
            }
            // cout<<curr<<endl;
            min_opt = min(min_opt, curr);
        }
        return min_opt;
    }
};