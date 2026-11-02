class Solution {
    public int minMoves2(int[] nums) {
        // find meadain = 
        // 4 + 5 + 3 + 4 
        int n = nums.length;
        int meadian ;
        Arrays.sort(nums);
        if((n & 1)== 1){
            meadian = nums[n/2];
        }else {
            meadian =(nums[(n-1)/ 2] + nums[ n / 2 ])/2;
        }
        int ans = 0;
        for(int num : nums){
            ans += Math.abs(meadian - num);
        }
        

        
        return ans;
    }
}
