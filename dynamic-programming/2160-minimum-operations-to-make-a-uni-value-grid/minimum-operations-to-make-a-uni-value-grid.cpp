class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<int>nums;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                nums.push_back(grid[i][j]);
            }
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return 0;
        int target=nums[n/2];
        for(int i=0;i<n;i++){
            if(nums[i]%x!=target%x)return -1;
            ans+=abs(target-nums[i])/x;
        }


         
        return ans;

    }
};