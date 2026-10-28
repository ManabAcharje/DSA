class Solution {
public:
    int m , n ;
    vector<vector<int>>grid;
    // unordered_map<int,int>memo;
    int memo[1001][1024];
    int solve(int i, int j , int xor_val){
        if(i == m-1 && j == n-1) return xor_val^grid[i][j];
        int key = i*n + j;
        if(memo[key][xor_val] != -1){
            return memo[key][xor_val];
        }
        int right = 1024;
        int down = 1024;

        if(i + 1 < m){
            right = solve(i+1,j, xor_val^grid[i][j]);

        }
        if(j + 1 < n){
            down = solve(i,j+1,xor_val^grid[i][j]);
        }
        return memo[key][xor_val] = min(right,down); 
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(memo,-1,sizeof(memo));
        this->grid = grid;
        return solve(0,0,0);
    }
};