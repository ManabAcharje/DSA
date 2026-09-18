class Solution {
public:
    int n;
    void dfs(int node, vector<vector<int>>& stones, vector<int>& visited) {
        visited[node] = 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                if (stones[i][0] == stones[node][0] ||
                    stones[i][1] == stones[node][1]) {
                    dfs(i, stones, visited);
                }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
         n = stones.size();
        vector<int> visited(n, 0);
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, stones, visited);
                groups++;
            }
        }
       return n - groups;
    }
};