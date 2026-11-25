class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> dp1(n, 0), dp2(n, 0);
        dp1[0] = 0;
       

        dp2[n-1] = 0;

        for (int i = 1; i < n; i++) {
            int a = abs(nums[i] - nums[i-1]);
            int b = (i>=2 ? abs(nums[i-1] - nums[i-2]) : INT_MAX );
            int cost ;
            if( a < b){
                cost = 1;
            }else{
                cost = a;
            }
            dp1[i] = dp1[i-1] + cost;
        }
        // for(int x : dp1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i = n -2 ; i >= 0 ; i--){
            int a  = nums[i+1] - nums[i];
            int b = (i+2 < n ? nums[i+2] - nums[i+1] : INT_MAX);
            int cost;
            if(a <= b){
                cost = 1;
            }else{
                cost = a; 
            }
            dp2[i] = dp2[i+1] + cost;
        }
        // for(int x  : dp2){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0];
            // l = 2
            int r = q[1];
            // r  = 0;
            if (l < r) {
                // cout<<"here ";
                ans.push_back(dp1[r] - dp1[l]);

            } else if(l == r) {
                // cout<<"sdjsgj ";
                (ans.push_back(0));
            }

            else {
                // cout<<"there ";
                // dp2 [2] - dp2[0];

                ans.push_back(dp2[r] - dp2[l]);
            }
        }
        return  ans;
    }
};