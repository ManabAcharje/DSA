class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();

        vector<int> haveBoxes(n, false);
        vector<int> processed(n, false);

        queue<int> q;
        for (int box : initialBoxes) {
            q.push(box);
            haveBoxes[box] = true;
        }

        int ans = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (processed[box])
                continue;

            if (status[box]) {
                ans += candies[box];
                processed[box] = true;
                for (int key : keys[box]) {
                    status[key] = 1;
                    if (haveBoxes[key] && !processed[key]) {
                        q.push(key);
                    }
                }
                for (int insideBox : containedBoxes[box]) {
                    haveBoxes[insideBox] = true;
                    q.push(insideBox);
                }
            }
        }
        return ans;
    }
};