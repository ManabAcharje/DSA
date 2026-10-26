class Solution {
public:
   vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,int>P;
    int m,n;
    vector<vector<int>> grid;
    bool bfs(int i , int j,vector<vector<bool>>&visited,int k ){
        queue<P> q;
        q.push({i,j});
        int sum = grid[i][j];
        while(!q.empty()){
            int sz = q.size();
            for(int kk = 0 ; kk < sz ; kk++){
                auto [i_,j_] = q.front();
                q.pop();
                for(auto d : dir){
                    int ni =  i_ + d[0];
                    int nj =  j_ + d[1];

                    if(ni>=0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] >= 1 && visited[ni][nj] == false){
                        visited[ni][nj] = true;
                        sum = ( sum % k + grid[ni][nj] % k)% k;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return sum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
     
        this->grid = grid;
        m =  grid.size();
 
        n =  grid[0].size();
        int island =0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; i++){
            for(int  j = 0 ;  j < n ; j++){
                if(!visited[i][j] && grid[i][j] >= 1) {
                    visited[i][j] = true;
                    bool x = bfs(i,j,visited,k);
                    if(x)island++;
                }
            }
        }
        return island;
    }
};