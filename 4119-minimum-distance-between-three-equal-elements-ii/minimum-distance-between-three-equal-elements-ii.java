class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;

        int i = 0;
        int j = 0;

        int ans = Integer.MAX_VALUE;

        HashMap<Integer, Integer> mp = new HashMap<>();

        while(j<n){

            int num = nums[j];

            mp.put(num,mp.getOrDefault(num,0)+1);

            if(mp.get(num)==3){
                while(nums[i]!=num){
                    mp.put(nums[i], mp.get(nums[i]) - 1);
                     i++;

                }
                ans = Math.min(ans, (j - i) * 2); 
                mp.put(nums[i], mp.get(nums[i]) - 1);
                i++;
            }
            j++;

        }
         return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}