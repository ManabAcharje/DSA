class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int greatest=*max_element(nums.begin(),nums.end());
        int smallest=*min_element(nums.begin(),nums.end());

        unordered_set<int>st;
        for(int &num:nums){
            st.insert(num);
        }
        vector<int>result;
        for(int i=smallest+1;i<greatest;i++){
            if(!st.count(i))result.push_back(i);
        }
        return result;
    }
};