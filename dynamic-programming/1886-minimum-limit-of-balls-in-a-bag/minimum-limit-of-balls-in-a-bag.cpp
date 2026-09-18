class Solution {
public:
    bool solve(vector<int>& nums,int target, int maxOpt){
        int opt=0;
        for(int num:nums){
            if(num<=target)continue;
            else{
                opt=opt+((num-1)/target);//<-------
                if(opt>maxOpt)return false;
            }
        }
        return opt<=maxOpt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i=1;
        int n=nums.size();

        int j=*max_element(nums.begin(),nums.end());

        while(i<=j){
            int mid=i+(j-i)/2;

            bool temp =solve(nums,mid,maxOperations);

            if(temp)j=mid-1;
            else i=mid+1;
        }
        return i;
    }
};