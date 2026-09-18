class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        
        // Build adjacency list (only need parent -> child for depth traversal)
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> depth(n, 0);
        int h = 1;
        
        queue<int> q;
        q.push(0);
        depth[0] = 1; // Root depth is 1 as per description

        // 1. BFS to find depth of each node and the overall tree height 'h'
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            h = max(h, depth[u]);
            
            for (int v : adj[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        // 2. Calculate the final sum using the correct formula
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return totalSum;
    }
};