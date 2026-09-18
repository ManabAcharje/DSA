class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int one=0;
        int zero=0;
        int two=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)one++;
            else if(nums[i]==2)two++;
            else zero++;
        }
        int k=0;
        while(zero){
            nums[k++]=0;
            zero--;
        }
        while(one){
            nums[k++]=1;
            one--;
        }
        while(two){
            nums[k++]=2;
            two--;
        }
        return ;
        
    }
};