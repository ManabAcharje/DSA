class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        for (int num : nums) {
            freq[num]++;
            
        }
        
        vector<int> ans;
        while (n) {
            for (int i = 0; i < 101; i++)
            {
                if (freq[i] != 0){
                    ans.push_back(i);
                    freq[i]--;
                    n--;
                }
            }
        }
        return ans;
    }
};