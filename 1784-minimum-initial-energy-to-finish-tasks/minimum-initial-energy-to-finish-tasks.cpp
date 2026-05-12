class Solution {
public:
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        }
    };

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), cmp());
        int energy = 0;
        int currEnergy = 0;
        for (int i = 0; i < n; i++) {
            int x = abs(tasks[i][1] - currEnergy);
            if (currEnergy < tasks[i][1]) {
                energy += x;
                currEnergy += x;
            }
            currEnergy -= tasks[i][0];
        }
        return energy;
    }
};