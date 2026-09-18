class Solution {
public:

    int rev(int n){
        int result=0;
        while(n){
            result=result*10+(n%10);
            n/=10;
        }
        return result;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();


        unordered_map<int,int>mp;
        int ans=INT_MAX;
        bool found=false;

        for(int i=0;i<n;i++){
            int rev_num=rev(nums[i]);
            // if(mp[nums[i]])// if mp of rev_Num already there i.e we have the reverse of it so compute the distance and modify it
            // another thing mp[nums[i]] is dangerous becasue 0 is a valid index
            if (mp.count(nums[i])) 
            {
                int idx = mp[nums[i]];// safe now
                ans=min(ans,i-idx);
                found=true;
            }
            mp[rev_num]=i;

        }
        return found?ans:-1;
    }
};