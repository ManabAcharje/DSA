class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        unordered_set <int> st;

        int max_len = 0;

        st.insert(nums.begin(),nums.end());
        
        for(auto num: st){
            if(!st.count(num-1)){//means it is the starting num;
                int len  = 1;
                int copy  = num;
                while(st.count(++copy)){
                    len++;
                }
                max_len = max(len,max_len);
            }
        }
        return max_len;

    }
};