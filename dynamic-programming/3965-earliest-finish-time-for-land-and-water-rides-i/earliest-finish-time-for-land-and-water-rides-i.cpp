class Solution {
public:

    int solve(vector<int>&a,vector<int>&b,vector<int>&c,vector<int>&d){
        int firstEndTime = INT_MAX;
        for(int i=0;i<a.size();i++){
            firstEndTime=min(firstEndTime,a[i]+b[i]);
        }

        int time=INT_MAX;
        for(int j=0 ; j < c.size() ; j++){
            if(c[j]>=firstEndTime){
                time=min( c[j] + d[j],time);
            }
            else{
                time = min(firstEndTime+d[j],time);
            }
        }
        return time;

    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1 =  solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int ans2 = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(ans1,ans2);
    }
};