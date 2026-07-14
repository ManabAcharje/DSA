class Solution {
public:
    int gcd(int a ,int b){
        if(a<b)return gcd(b,a);
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums.back());
    }
};