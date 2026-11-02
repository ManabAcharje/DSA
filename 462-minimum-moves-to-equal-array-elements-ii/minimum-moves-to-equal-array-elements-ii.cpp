class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n =  nums.size();
        vector<long long > pref(n,0), suff(n,0);
        //pref[i] stores the opts req to make 

        sort(nums.begin(),nums.end());
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1; i< n ;i++){
            pref[i] = pref[i-1] + nums[i];
            suff[n-i-1] = suff[n-i] + nums[n-i-1];
        }
        
        long long  min_moves = INT_MAX;
        for(int  i = 0 ; i < n ; i++){
            long long  left = (i>0) ? (long long)i*nums[i]- pref[i-1] : 0;
            long long  right = (i+1< n) ? suff[i+1] - (long long)(n-i-1)*nums[i] : 0;
            // cout<<"for i = "<<i<<endl;
            // cout<<left<< " "<<right<<endl;

            long long  curr_moves = left + right;
            min_moves = min(curr_moves , min_moves);
            
        }
        return (int)min_moves;
        


    }
};