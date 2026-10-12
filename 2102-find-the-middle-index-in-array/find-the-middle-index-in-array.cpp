class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n,0);
        vector<int>suff(n,0);
        suff[n-1] = nums[n-1];
        pref[0] = nums[0];
        for(int i = 1; i<n;i++){
            pref[i] = pref[i-1]+ nums[i];
            suff[n-i-1] = nums[n-1-i] + suff[n-i];
        }
        if(n==1) return 0;
        if(suff[1] == 0 )return 0;
        for(int i = 1 ; i<= n-2;i++){
            if(pref[i-1]  == suff[i+1])return i;

        }
        if( pref[n-2] == 0)return n-1;

        return -1;
    }
};