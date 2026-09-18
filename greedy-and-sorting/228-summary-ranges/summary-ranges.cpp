class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result; // Handle empty input

        int starting = nums[0];
        
        for (int i = 1; i <= nums.size(); i++) {
            // Check if we reached the end or found a gap
            if (i == nums.size() || nums[i] != nums[i-1] + 1) {
                int ending = nums[i-1];
                
                if (starting == ending) {
                    result.push_back(to_string(starting));
                } else {
                    result.push_back(to_string(starting) + "->" + to_string(ending));
                }
                
                // Update starting point for the next range
                if (i < nums.size()) {
                    starting = nums[i];
                }
            }
        }
        return result;
    }
};