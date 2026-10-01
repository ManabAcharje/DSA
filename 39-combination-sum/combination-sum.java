class Solution {
    List<List<Integer>> ans;
    int n;

    void solve(int i, int target, List<Integer> temp, int[] nums) {
        if (target == 0) {
            ans.add( new ArrayList<>(temp));
            // System.out.println("added");
            return;
        }
        if (i == n || target < 0)
            return;

        temp.add(nums[i]);
        solve(i, target - nums[i], temp, nums);
        temp.remove(temp.size()-1);
        solve(i + 1, target, temp, nums);

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        n = candidates.length;
        ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(0, target, temp, candidates);
        return ans;
    }
}