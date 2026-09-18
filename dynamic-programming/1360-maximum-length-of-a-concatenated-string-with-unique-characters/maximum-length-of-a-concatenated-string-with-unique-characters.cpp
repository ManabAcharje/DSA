class Solution {
public:
    /// _BIT MANIPULATION TECHNIQUE_ ///

    int solve(vector<int>&nums, int i,int n,int num){
        if(i==n)return __builtin_popcount(num);
        int include=0;
        int exclude=0;
        if(num & nums[i]){// means duplicate occurs so don't include;
            return solve(nums,i+1,n,num);
        }
        else{
            include=solve(nums,i+1,n,num|nums[i]);
            exclude=solve(nums,i+1,n,num);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        vector<int>nums;
        for(string &s:arr)
        {
            int num=0;
            bool duplicate=false;
            for(int i=0;i<s.size();i++){
                //bit already set then continue , because the i.e duplicate so need to
                int pos=s[i]-'a';
                if(num & (1<<pos)){
                    duplicate=true;
                    break;
                } 
                num=num|(1<<pos);
            }
            if(!duplicate)nums.push_back(num);
        }

        return solve(nums,0,nums.size(),0);
    }
};