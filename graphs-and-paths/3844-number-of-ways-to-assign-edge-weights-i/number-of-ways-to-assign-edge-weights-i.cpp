class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    unordered_map<int, vector<int>> adj;

    int dfs(int node, int parent) {
        int h = 0;

        for (int ngbr : adj[node]) {
            if (ngbr == parent) continue;

            h = max(h, 1 + dfs(ngbr, node));
        }

        return h;
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int h = dfs(1, -1);

        return (int)modPow(2, h - 1);
    }
};