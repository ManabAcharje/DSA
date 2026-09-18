class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // if i use sliding window 

        unordered_map<int,int> mp;
        int n = nums.size();

        int j = 0;
        int i = 0;

        int ans = INT_MAX;
        while(j<n){
            int num = nums[j];
            // cout<<"num: "<<num<<endl;
            mp[num]++;
            // cout<<mp[num]<<endl;
            if(mp[num]==3){
                ans= min(ans, (j-i)*2);
                
                while(nums[i]!=num){
                    mp[nums[i]]--;
                    i++;
                }
                ans= min(ans, (j-i)*2);
                mp[nums[i]]--;
                i++;

            }
            j++;
        }

        return ans== INT_MAX?-1:ans;

    }
};