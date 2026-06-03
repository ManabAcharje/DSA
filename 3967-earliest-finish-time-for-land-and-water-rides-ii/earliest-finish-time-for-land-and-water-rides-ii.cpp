class Solution {
public:
    int solve(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d){
        int firstEndingTime=INT_MAX;
        for(int i=0; i<a.size(); i++){
            firstEndingTime=min(a[i]+b[i] , firstEndingTime);
        }
        int secondEndingTime=INT_MAX;
        for(int j=0;j<c.size();j++){
            if(c[j]>=firstEndingTime)secondEndingTime=min(secondEndingTime,c[j]+d[j]);
            else{
                secondEndingTime=min(secondEndingTime,firstEndingTime+d[j]);
            }
        }
        return secondEndingTime;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            solve(landStartTime,landDuration,waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,landStartTime,landDuration)
            
        );
    }
};