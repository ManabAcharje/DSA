class Solution {
public:
    vector<vector<int>>ans;   
    int target; 
    int n; 
    void solve(int i,int curr,vector<int>&temp,vector<int>&candidates){
        if(i==n  || curr > target)return;
        if(curr == target){
            ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        solve(i,curr+candidates[i],temp,candidates);
        temp.pop_back();
        solve(i+1,curr,temp,candidates);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        n= candidates.size();
        vector<int>temp;
        solve(0,0,temp,candidates);
        return ans;
        
    }
};