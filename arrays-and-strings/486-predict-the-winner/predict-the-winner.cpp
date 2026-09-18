class Solution {
public:
vector<int> nums;
    int solve(int i , int j){

        if(i>j)return 0; 
        // i have two option one is to pick from first
        int opt1 = nums[i] - solve(i+1,j);
        int opt2 = nums[j] - solve(i,j-1);

        return max(opt1,opt2);



    }
    bool predictTheWinner(vector<int>& nums) {
        this->nums =  nums;
        int n = nums.size();
        
        return solve(0,n-1)>=0;
    }
};