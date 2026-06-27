class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>ans(1001,0);
        for(auto &trip : trips){
            int left = trip[1];
            int right = trip[2];
            int x = trip[0];
            for(int i = left ; i< right ; i++){
                ans[i]+=x;
                if(ans[i] > capacity)return false;
            }
        }
        return true;
    }
};
// 0 1 2 3 4 5 
// 0 2 2 2 2 2
          