class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int curr = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
             curr= max(nums[i], nums[i]+curr);
            ans = max(ans,curr);
        }
        return ans;
    }
};