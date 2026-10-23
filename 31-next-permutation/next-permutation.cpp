class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int i = n - 1;
        int j = n - 2;
        while (j >= 0 && nums[j] >= nums[j + 1])
            j--;
        if (j < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (i = n - 1; i > j; i--) {
            if (nums[i] > nums[j])
                break;
        }
        swap(nums[j], nums[i]);
        j++;
        reverse(nums.begin() + j, nums.end());

        // first point of diff
    }
};