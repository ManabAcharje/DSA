class Solution {
public:
    vector<vector<int>>result;
    
    int  n ;

    void solve(int i , vector<int>& temp, vector<int>& nums){
        if(i == n){result.push_back(temp);return ;}

        cout<<i<<endl;
        temp.push_back(nums[i]);
        solve(i+1,temp,nums);
        temp.pop_back();
        solve(i+1,temp,nums);


    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        
        vector<int>temp;
        solve(0,temp,nums);
        return result ; 

    }
};