class Solution {
public:
    long long customKdane (vector<int> &nums){
       
        long long  mini = 0;
        long long  prev = 0;

        for(int i = 0 ;i+1 < nums.size(); i+=2){
            long long  curr = nums[i]+ nums[i+1];

            prev = min(curr+prev,curr);
            mini = min(prev,mini);

            if(prev > 0) prev = 0;
            
        }
        
        prev = 0;
        for(int i = 1 ;i+1 < nums.size(); i+=2){
             long long curr = nums[i]+ nums[i+1];

            prev = min(curr+prev,curr);
            mini = min(prev,mini);

            if(prev > 0) prev = 0;
            
            
        }
        return mini;
        
    }
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);

        long long  v = nums[0];

        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = ((i & 1) ? -nums[i] : nums[i]);
            v += pref[i];
        }
        // cout<<"V  = "<<v<<endl;

        // for (auto &i : pref) {
        //     cout << i << " ";
        // }
        // cout << endl;
       
        long long  minSubArraySum = customKdane(pref);
        // cout<<"minSub "<<minSubArraySum;

        return v - 2*minSubArraySum;
    }
};