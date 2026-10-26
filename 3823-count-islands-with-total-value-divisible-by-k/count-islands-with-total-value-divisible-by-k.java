class Solution {
    int [][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int [][]grid;
    private boolean bfs(int i , int j , boolean[][] visited , int k){
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i,j}); // <---- offer and push 
        int sum = grid[i][j];
        while(!q.isEmpty()){
            int sz = q.size();
            for(int kk = 0 ; kk < sz  ; kk++){
                int [] curr = q.poll(); // <----- poll and front();
                int i_ = curr[0];
                int j_ = curr[1];
                for(int []d : dir){
                    int ni = i_ + d[0];
                    int nj = j_ + d[1];
                    if(ni>=0 && nj >=0 && ni < m && nj < n && grid[ni][nj]>=1 && !visited[ni][nj]){
                        visited[ni][nj] = true;
                    sum = (sum % k + grid[ni][nj] % k ) % k ;
                    q.offer(new int[]{ni,nj});

                    }
                }
            }
        }
        return sum % k == 0 ;
    }
    public int countIslands(int[][] grid, int k) {
        this.grid = grid;

        int islands = 0;
         m = grid.length;
         n = grid[0].length;
        boolean [][] visited = new boolean[m][n];
        for(int i = 0 ;i< grid.length; i++){
            for(int j = 0 ; j <grid[0].length ;j++){
                if(!visited[i][j] && grid[i][j]>=1){
                    visited[i][j] = true;
                    if(bfs(i,j,visited,k) == true)islands++;
                }
            }
        }
        return islands;
    }
}