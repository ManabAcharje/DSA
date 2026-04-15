class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        priority_queue<int,vector<int>,greater<int>>minH;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        
            if(!st.count(nums[i])){
                minH.push(nums[i]);
                st.insert(nums[i]);
            }
            if(minH.size()>3)minH.pop();
            
        }
        if(minH.size()>=3)
        return minH.top();
        return maxi;
        

    }
};