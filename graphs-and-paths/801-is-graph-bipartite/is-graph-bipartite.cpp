class Solution {
public:
    bool checkBipartiteBFS(int node, int colorToAssign, vector<vector<int>>& graph,
                      vector<int>& colors) {
        queue<int> q;
        q.push(node);
        colors[node] = colorToAssign;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (colors[v] == colors[u])
                    return false;

                else if (colors[v] == -1) {
                    colors[v]=1-colors[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (checkBipartiteBFS(i, 1, graph, colors) == false)
                    return false;
            }
        }
        return true;
    }
};