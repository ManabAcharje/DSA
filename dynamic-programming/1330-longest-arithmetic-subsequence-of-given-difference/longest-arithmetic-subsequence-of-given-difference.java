class Solution {
    Map<Integer,Integer> dp = new HashMap<>();
    public int longestSubsequence(int[] arr, int diff) {
        int ans=1;

        for(int num:arr){
            dp.put(num,dp.get(num-diff)==null? 1:dp.get(num-diff)+1);
            ans=Math.max(ans,dp.get(num));
        }
        return ans;
    }
}