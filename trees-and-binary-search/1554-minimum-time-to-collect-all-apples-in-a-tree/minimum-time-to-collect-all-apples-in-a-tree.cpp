class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<bool> visited;
    void dfs(int node, vector<bool>& hasApple) {
        visited[node] = true;
        for (auto& child : adj[node]) {
            if (!visited[child]) {
                dfs(child, hasApple);

                if (hasApple[child])
                    hasApple[node] = true;
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        visited.resize(n, false);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        dfs(0, hasApple);
        for (int i = 1; i < hasApple.size(); i++) {
            if (hasApple[i])
                ans += 2;
        }
        return ans;
    }
};