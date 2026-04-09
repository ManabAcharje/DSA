class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int parimeter=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(i==0 || grid[i-1][j]==0)parimeter++;
                    if(j==0 || grid[i][j-1]==0)parimeter++;
                    if(i== m-1 || grid[i+1][j]==0)parimeter++;
                    if( j==n-1 || grid[i][j+1]==0)parimeter++;
                    
                }
            }
        }
        return parimeter;
    }
};