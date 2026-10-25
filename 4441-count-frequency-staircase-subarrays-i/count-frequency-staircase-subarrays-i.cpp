class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // cout<<"for i = "<<i<<endl;
            int rank = 0;
            int balanced = 0;

            unordered_map<int, int> ranks;
            unordered_map<int, int> freq;

            for (int j = i; j < n; j++) {

                if (freq.count(nums[j]) == 0) {
                    ranks[nums[j]] = (++rank);
                }

                freq[nums[j]]++;
         
                if (freq[nums[j]] > ranks[nums[j]])
                    break;
                else if (freq[nums[j]] == ranks[nums[j]]) 
                    balanced++;
               
                if (balanced == rank){
                    ans++;
                }
            }
            // for(auto it : freq)
            // {
            //     cout<<it.first << " = "<<it.second<<endl;
            // }
            // cout<<"\n";
            // for(auto it : ranks)
            // {
            //     cout<<it.first << " = "<<it.second<<endl;
            // }
            // cout<<endl;
            // cout<<endl;
        }
        return ans;
    }
};