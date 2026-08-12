class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // sliding window +  unordered_map;
        //  what i will do if the freq of any char becomes greater than k then i
        //  will move the i  the pointer until freq[char]<=k and update the
        //  maxLen each time;
        // return max Length;

        int n = nums.size();
        int i = 0;
        
        int longest = 0;

        unordered_map<int,int>freq;
        for(int j = 0; j< n;j++){
            freq[nums[j]]++;
            while(freq[nums[j]]>k){
                freq[nums[i]]--;
                i++;
            }
            longest= max(longest,j-i+1);
        }
        return longest;

       
        
    }
};