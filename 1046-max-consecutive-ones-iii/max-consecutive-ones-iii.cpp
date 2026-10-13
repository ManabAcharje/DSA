class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //    max_sub with atmost k 0 ;

        int ans = 0;

        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeros_count = 0;
        while (j < n) {
            int curr = nums[j];
            if (curr == 0)
                zeros_count++;

            while (i <= j && zeros_count > k) {
                if (nums[i] == 0)
                    zeros_count--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};