class Solution {
public:
    const int m=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        
        for(auto query:queries){
            int l=query[0];
            int r=query[1];
            int k=query[2];
            int v=query[3];
            while(l<=r){
                nums[l]=((long long)nums[l]*v)%m;
                l+=k;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};