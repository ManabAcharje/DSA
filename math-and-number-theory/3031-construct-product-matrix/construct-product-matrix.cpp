class Solution {
public:
    // help from codestorywithmik
    const int Mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>p(m,vector<int>(n,1));
        long long suffix=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                p[i][j]=suffix;
                suffix=(suffix*grid[i][j])%Mod;
            }
        }
        long long prefix=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[i][j]=(prefix*p[i][j])%Mod;
                prefix =(prefix*grid[i][j])%Mod;
            }
        }
        return  p;

        
        
    }
};