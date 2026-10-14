class Solution {
public:
    const int mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        int curr_resource = k;
        long cost = 0;
        long long total_inc = 0;

        for (int req : nums) {

            if (curr_resource >= req) {

                curr_resource -= req;

            } else {
                int need = req - curr_resource;

                int x = need / k;
                if (k * x != need) {
                    x++;
                }

                curr_resource = curr_resource + k * x - req; // 1  + 4 - 2

                total_inc = (total_inc % mod + x % mod) % mod;
            }
        }
        cost += (total_inc  * (total_inc  + 1) / 2) % mod;
        return (int)cost;
    }
};