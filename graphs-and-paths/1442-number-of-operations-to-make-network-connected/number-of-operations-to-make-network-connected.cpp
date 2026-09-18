class Solution {
public:
    vector<int> visited;
    unordered_map<int, vector<int>> adj;

    void bfs(int node) {
        queue<int> q;
        visited[node] = 1;
        q.push(node);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& v : adj[curr]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = 0;
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // how many bfs calls  needed is components;
        // how many extra wires;
        //

        visited.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i);
                components++;
            }
        }
        if (connections.size() < n - 1)
            return -1;

        return components - 1;
    }
};