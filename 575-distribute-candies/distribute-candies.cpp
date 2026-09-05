class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        int diff= 0;
        int n = nums.size();
        unordered_set<int>st;
        for(int i =0 ;i<n;i++){
            if(st.count(nums[i])==1){
                continue;
            }
            else{
                diff++;
                st.insert(nums[i]);
            }
        }
        cout<<diff;
        int canEat = n/2;

        return min(diff,canEat);


    }
};