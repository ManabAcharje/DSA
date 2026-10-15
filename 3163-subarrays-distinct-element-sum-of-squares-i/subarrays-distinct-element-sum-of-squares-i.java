class Solution {
    public int sumCounts(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            Set<Integer> distinct = new HashSet<Integer>();

            for (int j = i; j < n; j++) {
                distinct.add(nums.get(j));
                int x = distinct.size();
                ans += (x * x);
            }
        }
        return ans;
    }
}