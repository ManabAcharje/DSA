class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 0;
        unordered_map<int,int>freq;

        while(j<n){
            int x = nums[j];
            freq[x]++;
            if(freq[x]<=k){
                len = max(len,j-i+1);
                j++;
            }
            else{
                while(freq[x]!=k){
                    freq[nums[i]]--;;
                    i++;
                }
                len = max(len,j-i+1);
                j++;
            }


        }
        return len;
    }
};