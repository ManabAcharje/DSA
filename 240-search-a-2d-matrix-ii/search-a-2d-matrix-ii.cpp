class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find the row use bs
        // then find the coluse  binary search
        int m = matrix.size();
        int n  =matrix[0].size();
        for(auto &row : matrix){
            for( auto &cell : row){
                if(cell == target)return true;
            }
        }
        
        
        
        return false;


    }
};