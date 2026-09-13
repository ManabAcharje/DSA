class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, array<int,4>> mp;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            mp[num][0]++;
            int f = mp[num][0];

            if(f == 1) {
                mp[num][1] = i;       
            }
            else if(f == 2) {
                mp[num][2] = i - mp[num][1]; 
                mp[num][1] = i;               
                mp[num][3] = 1;              
            }
            else {
                
                if(mp[num][3] == 1) {
                    int curr_diff = i - mp[num][1];

                    if(curr_diff != mp[num][2])
                        mp[num][3] = 0;
                }

                mp[num][1] = i;
            }
        }

        int ans = 0;

        for(auto it : mp) {
            if(it.second[0] >= 3 && it.second[3] == 1)
                ans++;
        }

        return ans;
    }
};