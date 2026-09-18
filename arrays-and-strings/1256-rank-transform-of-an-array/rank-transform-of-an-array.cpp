class Solution {
public:
    int rank(int target, vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int ans = -1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return ans;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            arr[i] = rank(arr[i], temp) + 1;
        }

        return arr;
    }
};