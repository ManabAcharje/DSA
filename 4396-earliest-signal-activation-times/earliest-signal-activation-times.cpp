class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<long long> ans(n, -1);
        vector<int> counts(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int delay = edge[2];
            adj[u].push_back({v, delay});
        }

        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        ans[0] = 0;
        counts[0] = requiredSignals[0];
        
        for (auto& edge : adj[0]) {
            int ngbr = edge.first;
            long long delay = edge.second;
            pq.push({delay, ngbr});
        }

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (ans[u] != -1) continue;

            counts[u]++;
            
            if (counts[u] == requiredSignals[u]) {
                ans[u] = t;
                
                for (auto& edge : adj[u]) {
                    int ngbr = edge.first;
                    long long delay = edge.second;
                    pq.push({t + delay, ngbr});
                }
            }
        }

        return ans;
    }
};