class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int i = 1; i < 101; i++) {
            int flag = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == k * i) {
                    flag = 0;
                }
            }
            if (flag != 0) {
                return k * i;
            }
        }
        return k*101;
    }
};