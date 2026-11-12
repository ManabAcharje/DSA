class Solution {
public:
    int ans = 1;
    bool reversed = false;

    int longestMonotonicSubarray(vector<int>& nums) {

        stack<int> st;
        int i = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (st.empty() || st.top() < curr) {
                st.push(nums[i]);
            } else {
                ans = max(ans, (int)st.size());
                st = stack<int>();
                st.push(nums[i]);
            }
        }
        ans = max(ans,(int) st.size());
        if (!reversed) {
            reversed = true;
            reverse(nums.begin(), nums.end());
            ans = max(ans, longestMonotonicSubarray(nums));
        }
        return ans;
    }
};