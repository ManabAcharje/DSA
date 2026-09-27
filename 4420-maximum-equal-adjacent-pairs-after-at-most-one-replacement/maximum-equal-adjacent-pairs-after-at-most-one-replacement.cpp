class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int ans = 0;

        map<pair<int,int> , int>freq;
        for(int  i = 0; i<n-1;i++){

            int x = nums[i];
            int y = nums[i+1];

            if(x == y){ans++;continue;}

            if(x>y){
                swap(x,y);
            }
            int curr = ++freq[{x,y}];

            if(curr>maxi){
                maxi = max(curr,maxi);
            }




        }
        return ans+maxi;
    }
};