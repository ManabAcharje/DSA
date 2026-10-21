class Solution {
    int n;
    int[] nums;
    int dp[];
    public int solve(int i) {
        if (i >= n)
            return 2 * n;
        if (i == n - 1) {
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int ans = 2 * n;
        for (int i_ = 1; i_ <= nums[i]; i_++) {
            int temp = 1 + solve(i + i_);
            ans = Math.min(temp, ans);

        }
        return dp[i] = ans;
    }

    public int jump(int[] nums) {
        this.nums = nums;

        n = nums.length;
        dp = new int[n];
        for(int i = 0 ; i < n ; i++){
            dp[i] = -1;        
        }
        int ans = solve(0);
        return ans;

    }
}