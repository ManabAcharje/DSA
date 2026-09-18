class Solution {
public:
    vector<int> nums;

    int binarySearch(int i, int j, int target) {
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        this->nums = nums;

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        // find pivot (minimum element index)
        while (i < j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] > nums[j])
                i = mid + 1;
            else
                j = mid;
        }

        int pivot = i;

        if (target >= nums[pivot] && target <= nums[n - 1])
            return binarySearch(pivot, n - 1, target);
        else
            return binarySearch(0, pivot - 1, target);
    }
};