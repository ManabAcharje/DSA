class Solution {
public:
    int n;
    vector<long long >t;
    long long solve(int i, vector<vector<int>> & q){

        if(i >= n)return 0;

        if(t[i] != -1)return t[i];
        
        long long  take=q[i][0]+solve(i+q[i][1]+1,q);
        long long  notTake=solve(i+1 ,q);

        return t[i]= max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        /* 
            so i have choice to solve or not ;

        */

        n=questions.size();
        t.clear();
        t.assign(n,-1);
        return solve(0,questions);
    }
};