class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // so if i think i have only one room
        // int that case
        // at time 1 room =1
        // at time 1 another one tries to come so we can't accept him'
        // i will greedily chose that one to say which is going to finish soon
        // at time 2 i m free but again at time 3 one more is coming so it can
        // come and so one

        // sort based on first start time
        sort(intervals.begin(), intervals.end());

        int count = 0; // to store number of intervals to remove
        int lastEnds = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= lastEnds) {
                lastEnds = intervals[i][1];
                continue;

            } else {
                lastEnds = min(lastEnds, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};