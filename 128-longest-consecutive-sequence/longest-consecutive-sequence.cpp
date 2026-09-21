class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        unordered_set <int> st;
        unordered_map<int,int>mp;

        // unordered_set<int > seen ;
        int max_len = 0;

        st.insert(nums.begin(),nums.end());
        for(int original_num : nums){
            if(mp.count(original_num))continue;
            int len = 1;
            int curr_num = original_num;
            while(st.count(curr_num+1)){
                if(mp[curr_num+1]>=1){
                    len+=mp[curr_num+1];
                    break;
                }
                else len++;
                curr_num++;
            }
            mp[original_num] = len;
            max_len = max(len ,max_len);
            
        }
        // for(auto it: mp){
        //     cout<<it.first <<" "<<it.second<<endl;
        // }
        // cout<<max_len;
        return max_len;

    }
};