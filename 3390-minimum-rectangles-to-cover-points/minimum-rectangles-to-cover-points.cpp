class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int curr = w;
        int ans = 1;
        for(int i = 0 ; i < points.size()-1 ; i++){
            int d = points[i+1][0] - points[i][0];
            if(d  <= curr){
                curr-=d;
            }else{
                ans += 1;
                curr = w;
            }
        }
        return ans;
    }
};