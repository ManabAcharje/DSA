class Solution {
public:
    vector<vector<bool>>visited;
    vector<vector<int>>grid;
    
    vector<vector<int>>dir = {{0,-1},{0,1},{1,0},{-1,0}};
    int m , n;
    bool  bfs(int i , int j ){
        queue<pair<int,int>>q;
        bool flag = true;
        q.push({i,j});
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0  ; k < sz ; k++){
            
                auto[x,y] = q.front();
                if(x == 0 || y == 0 || x == m-1 || y == n-1 )flag = false;
                q.pop();
                for(auto d : dir){
                    int ni = x + d[0];
                    int nj = y + d[1];
                    if(ni>=0 && nj >=0 && ni < m && nj < n && grid[ni][nj] != 1 && visited[ni][nj] == false ){
                        q.push({ni,nj});
                        visited[ni][nj] = true;
                    }
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        this->grid  = grid;

         m = grid.size();
         n = grid[0].size();
        int island = 0;

        visited.resize(m,vector<bool>(n,false));
        for(int i = 1 ; i < m ; i++){
            for(int j =1 ; j <  n ; j ++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    visited[i][j] = true;
                    if(bfs(i,j))
                        island++;
                }
            }
        }
        return island;
    }
};