class Solution {
public:
    vector<vector<int>> ans;
    int n,k;
    void solve(int i,vector<int> &temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return ;
        }
        if(i>n)return;
        for(int idx = i ; idx <= n; idx++){
            temp.push_back(idx);
            solve(idx+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int>temp;
        solve(1,temp);
        return ans;
    }
};