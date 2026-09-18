class Solution {
public:
    int findFirstIdx(int x, vector<int>& nums, int start) {
        int i = start;
        int j = nums.size() - 1;
        int res = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == x) {
                res = mid;
                j=mid-1;
            } else if (nums[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return res;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            return intersect(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result;
        int lastFoundIdx = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < n2; i++) {
            int foundIdx = findFirstIdx(nums2[i], nums1, lastFoundIdx);
            if (foundIdx != -1) {
                result.push_back(nums2[i]);
                lastFoundIdx = foundIdx + 1;
            }
        }
        return result;
    }
};