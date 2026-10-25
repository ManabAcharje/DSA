class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> diffArr(n);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // cout<<"i = " <<i << endl;
            ans += nums[i];
            // cout<<"ans = "<<ans<<endl;

            string s = to_string(nums[i]);
            sort(s.begin(), s.end(), greater<>());
            // cout<< "s = "<<s<<endl;

            int num = stoi(s);
            // cout<<"num = "<<num<<endl;
            int diff = (num - nums[i]);
            if (diff > 0) {
                diffArr[i] = {diff, i};
            }else{
                diffArr[i] = {0, i};
            }
            // cout<<endl<<endl;

        }

        sort(diffArr.begin(), diffArr.end());
        // for(auto x : diffArr){
        //     cout<<x[0] << " " <<x[1]<<endl;
        // }
        int j = n - 1;
        while (k) {
            ans += diffArr[j][0];
            j--;
            k--;
        }
        return ans;
    }
};