class Solution {
public: 
    int m,n;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void bfs(int i, int j ,vector<vector<int>> & grid){
        queue<pair<int,int>>q;

        grid[i][j]=0;
        q.push({i,j});
        while(!q.empty()){
            auto [ni,nj]=q.front();
            q.pop();
            for(auto d: dir){
                int i_ = ni+ d[0];
                int j_ = nj+ d[1];
                if(i_>= 0 && j_>=0 && i_<m && j_<n){
                    if(grid[i_][j_]==1){
                        grid[i_][j_]=0;
                        q.push({i_,j_});
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //m*n binary matrix
        //approach is from boundary cell with 1 run dfs/bfs converto it 0:
        //finally count no of  1;


        m = grid.size();
        n = grid[0].size();

        for(int  i= 0 ;i<m;i++){
            if(grid[i][0]==1){
                bfs(i,0,grid);
            }
            if(grid[i][n-1]==1){
                bfs(i,n-1,grid);
            }
        }

        for(int  j= 0 ;j<n;j++){
            if(grid[0][j]==1){
                bfs(0,j,grid);
            }
            if(grid[m-1][j]==1){
                bfs(m-1,j,grid);
            }

        }
        int ans= 0;
        for(auto &row:grid){
            for(auto &x:row){
                if(x==1)ans++;
            }
        }
        return ans;

    }
};