class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //use 
        int result=0;
        for(int bit=0; bit<32 ;bit++){
            int cnt=0;
            for(int num:nums){
                if((num>>bit)&1){
                    cnt++;
                }
            }
            if(cnt%3)
                result|=(1<<bit);

        }
        return result;
    }
};