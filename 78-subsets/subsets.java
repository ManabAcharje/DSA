class Solution {
    public    List<List<Integer>> result = new ArrayList<>();
    public   int n ;
    void solve(int i,List<Integer> temp, int[]nums){
        if(i == n){
            result.add(new ArrayList<>(temp));
            return ;
        }
        temp.add(nums[i]);
        solve(i+1,temp,nums);
        temp.remove(temp.size()-1);
        solve(i+1,temp,nums);

    }
    public List<List<Integer>> subsets(int[] nums) {
        n =nums.length;
        List<Integer> temp = new ArrayList<>();
        solve(0,temp,nums);
        return result;
    }
}