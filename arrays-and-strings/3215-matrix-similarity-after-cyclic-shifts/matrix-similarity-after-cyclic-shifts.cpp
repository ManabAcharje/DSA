class Solution {
public:
    
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        // if alternate or all equal return true;
        for (auto& row : mat) {
           for(int i=0;i<row.size();i++){
            if(row[i]!=row[(i+k)%n]){
                return false;
            }
           }
        }
        return true;
    }
};