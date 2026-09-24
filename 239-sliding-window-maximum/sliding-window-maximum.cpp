class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        unordered_map<int,int>freq;
        priority_queue<int>maxH;

        int idx = 0;
        int i = 0;
        for(int j = 0 ; j < n; j++){
           

           int curr = nums[j];
           freq[curr]++;
           maxH.push(curr);

           if(j-i+1 < k){
                continue;
           }
           else if(j-i+1 == k){
                while(maxH.size()>0 && freq[maxH.top()]==0)maxH.pop();   
                ans[idx++] = maxH.top();
                freq[nums[i++]]--;     
           }


        }
        return ans;
    }
};