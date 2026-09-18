class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);

        vector < vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size() ; i++) {
            int a = ans.back()[0];
            int b = ans.back()[1];
            int c = intervals[i][0];
            int d = intervals[i][1];

            // if non overlapping then simply push_back();

            if (b < c)
                ans.push_back({c,d});
            else {
                ans.pop_back();

                int x = min(a, c);
                int y = max(b, d);
                ans.push_back({x, y});
            }
        }
        return ans;
    }
};