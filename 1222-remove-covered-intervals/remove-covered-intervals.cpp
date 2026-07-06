class Solution {
public:
    bool check(int l ,int r,vector<vector<int>> &covered_intervals){
        for(auto &interval: covered_intervals){
            int a = interval[0];
            int b = interval[1];
            if(l>=a && r<=b)return true;

        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // remove intervals 
        // i need to remove intervals that have been coved;
        sort(intervals.begin(),intervals.end(),[](auto &a ,auto &b){
            if(a[0] == b[0])return a[1]>b[1];
            return a[0]<b[0];
        });

        int  n = intervals.size();
        vector<vector<int>>covered_intervals;
        int removed= 0;

        for(auto &interval: intervals){
            int l = interval[0];
            int r = interval[1];
            if(check(l,r,covered_intervals))removed++;
            else{
                covered_intervals.push_back({l,r});
            }
        }
        return n - removed;

    }
};