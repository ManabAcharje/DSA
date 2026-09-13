class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        unordered_map<int,pair<int,int>> mp;
    
        for(int i = 0; i<n;i++){
            int num  = nums[i];
            // cout<<num<<"\n";
            

            mp[num].first++;
            int &f  = mp[num].first;
            // cout<<"freq: "<<f<<endl;

            if(f == 1){
                mp[num].second = i;

            }
            else if(f==2){
                int first_idx = mp[num].second;
                int k = 2 * i- first_idx;
                if( k<n && nums[k] == num ){ans++;mp[num].second = -1;}
            }
            else if(f==4 && mp[num].second == -1)ans--;

        }
        return ans;
        
    }
};