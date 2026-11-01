class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1 2 3 4 
        // 2 3 4 4 
        // 3 4 5 4 
        // 4 5 5 5 
        // 6 6 6 5 
        // 6 7 7 6
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int moves = 0 ;
        for(int i = 1 ; i < n ; i++){
            moves+= (nums[i] - nums[0]);
        }
        return moves;


        

    }
};