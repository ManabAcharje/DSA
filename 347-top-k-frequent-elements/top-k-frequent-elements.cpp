class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {

    
       priority_queue<P,vector<P>,greater<P>>minH;
       unordered_map<int,int>freq;
       for(int num: nums){
            freq[num]++;
       }

       for(auto [n,f] : freq){
            minH.push({f,n});
            if(minH.size()>k){
                minH.pop();
            }
       }
       vector<int>ans;
       while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();

       }
       return ans;
    }
};