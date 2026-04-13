class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();//n=3

        int x=nums[0];//x=3
        int count=1;//count=1
        for(int i=1;i<n;i++){
            if(count==0){
                count=1;
                x=nums[i];
                continue;
            }
            if(nums[i]==x)count++;
            else{
                count--;

            }
        }
        return x;
    }
};
/*
    i=1
    nums[i]!=nums[i-1] so count--=count=0;as count=0 new x=nums[i]==2;
    i=2so
*/