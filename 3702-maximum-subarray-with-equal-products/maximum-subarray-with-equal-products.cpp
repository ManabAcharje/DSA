class Solution {
public:
    int gcd(int a , int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int maxLength(vector<int>& nums) {
         int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = nums[i];
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                
                l = (l / gcd(l, nums[j])) * nums[j];

                if (prod == l * g) {
                    maxLen = std::max(maxLen, j - i + 1);
                }

                if (prod > 25200) break;
            }
        }
        return maxLen;
    }
};