class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<bool>visited;
    bool dfs(int source,int destination){
        visited[source]=true;
        if(source==destination)return true;
        for(int ngbr:adj[source]){
            if(ngbr==destination)return true;
            else{
                if(!visited[ngbr]){
                    if(dfs(ngbr,destination))return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.assign(n,false);
        // i use a dfs or bfs from source if we get destination then true else false
        // ii we can use DSU
        
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        
        return dfs(source,destination);
    }
};