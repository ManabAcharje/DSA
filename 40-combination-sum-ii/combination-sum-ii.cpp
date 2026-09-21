class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(int idx, int target, vector<int>& temp, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == n)
            return;
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i - 1] == nums[i]) {
                continue;
            }
            if (target >= nums[i]) {
                temp.push_back(nums[i]);
                solve(i + 1, target - nums[i], temp, nums);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> temp;
        solve(0, target, temp, nums);
        return ans;
    }
};