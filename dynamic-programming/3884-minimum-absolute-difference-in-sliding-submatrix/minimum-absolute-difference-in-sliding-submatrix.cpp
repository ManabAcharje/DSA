class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans( (m - k + 1),vector<int>(n - k + 1));
        
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                unordered_map<int,int>mp;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        mp[grid[r][c]]++;
                    }
                }
                vector<int>nums;
                for(auto &it:mp){
                    int num=it.first;
                    nums.push_back(num);
                }
                sort(nums.begin(),nums.end());
                int mini=INT_MAX;
                if(nums.size()==1){
                    ans[i][j]=0;
                    continue;
                }
                for(int i=1;i<nums.size();i++){
                    mini=min(abs(nums[i]-nums[i-1]),mini);
                }
                ans[i][j]=mini;
                
            }
        }
        return ans;

    }
};