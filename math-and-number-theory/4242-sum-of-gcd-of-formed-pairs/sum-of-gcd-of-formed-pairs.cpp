class Solution {
public:
    int gcd(int a , int b ){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        //gcd of two number is  
        int mxi = nums[0];
        for(int i = 1 ;i < nums.size(); i++){
            mxi = max(mxi,nums[i]);
            nums[i] = gcd(nums[i],mxi);
        }
        int i= 0;
        int j = nums.size()-1;
        sort(nums.begin(),nums.end());
        long long sum = 0;
        while(i<j){
            sum+= gcd(nums[i],nums[j]);
            i++;
            j--;

        }
        return sum;
    }
};