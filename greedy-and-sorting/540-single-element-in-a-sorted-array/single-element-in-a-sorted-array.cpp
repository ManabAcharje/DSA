class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1, 1 , 2 , 3 ,3 ,4, 4,8,8
        // second element of the pair should be at  odd idx
        // if it is at even idx then move left else move right;

        int i = 0;
        int n = nums.size();
        int j = n - 1;
        if (n == 1)
            return nums[0];

        while (i <= j) {
            int mid = i + (j - i) / 2; // n = 7
            // mid = 3;
            // i = 4 j = 6  mid = 5;

            if (
                ((mid - 1 == -1) 
                    || 
                    (nums[mid - 1] != nums[mid])
                ) &&
                    (
                        (nums[mid + 1] != nums[mid]) 
                    ||
                        (mid + 1 == n)
                    )
                )
                return nums[mid];
            else if (nums[mid] == nums[mid + 1]) {
                if (((mid + 1) % 2) == 0)
                    j = mid - 1;
                else {
                    i = mid + 1;
                }
            } else if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0)
                    j = mid - 1;
                else
                    i = mid + 1;
            }
        }
        return -1;
    }
};