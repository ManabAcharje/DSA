class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            vector<int> &v = mp[nums[i]];
            if (v.size() == 0) {
                v.push_back(i);
                continue;
            }
            if (abs(i - v.back()) <= k)
                return true;
            else {
                v.push_back(i);
            }
        }
        return false;
    }
};