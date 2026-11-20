class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for(int i = 0 ; i< nums.size();  i++){
        //     cout<<nums[i]<<" ";

        // }
        // cout<<endl;

        unordered_map<int, int> lcs;
        int max_len = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            lcs[nums[i]] = max(lcs[nums[i]], lcs[nums[i] + 1] + 1);
            lcs[nums[i] + 1] = max(lcs[nums[i] + 1], lcs[nums[i] + 2] + 1);
            max_len = max({lcs[nums[i]], lcs[nums[i] + 1],max_len});
        }

        return max_len;
    }
};