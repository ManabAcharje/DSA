class Solution {
public:
    vector<vector<int>>visited,grid;
    int m , n;
    int remaining;
    const vector<vector<int>> dir= {{0,1},{0,-1},{1,0},{-1,0}};
    
    int solve(int i,int j){
        if(grid[i][j] == 2){
            return remaining == 0 ? 1 : 0;
        }
        
        int ans = 0;
    
        for(const auto& d: dir){
            int ni = i+d[0];
            int nj = j+d[1];

            if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj] && grid[ni][nj]!=-1){
                visited[ni][nj] = true;
                remaining --;

                ans += solve(ni,nj);

                visited[ni][nj] = false;
                remaining ++; 
                
            }
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        remaining  = 0;
        int x , y ;
    
        visited.resize(m,vector<int>(n,0));
        for(int i = 0 ;i <m; i++){
            for(int j = 0 ; j<n;j++){
                if(grid[i][j]==1){x = i; y = j;}
                else if(grid[i][j]==0 || grid[i][j] == 2)remaining++;
            }
        }
        // cout<<remaining<<" "<<endl;
        visited[x][y] = 1;
        return solve(x,y);


    }
};