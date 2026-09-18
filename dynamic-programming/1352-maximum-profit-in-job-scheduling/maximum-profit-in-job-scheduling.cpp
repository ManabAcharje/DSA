class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> starts;
    vector<int> dp;
    int n;

    int solve(int i) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int next = lower_bound(starts.begin(), starts.end(), jobs[i][1]) - starts.begin();

        int take = jobs[i][2] + solve(next);
        int notTake = solve(i + 1);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();

        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        for (auto &job : jobs)
            starts.push_back(job[0]);

        dp.assign(n, -1);

        return solve(0);
    }
};