class Solution {
public:
    int n;
    vector<bool>visited;
    unordered_map<int,vector<int>>adjList;

    bool dfs(int s, int d){
        if(s==d)return true;
        visited[s]=true;

        for(auto &ngbr:adjList[s]){
            if(visited[ngbr]==false){
                if(dfs(ngbr,d))return true;
                // visited[ngbr]=true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        this->n=n;
        visited.assign(n,false);
        for(auto & edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        return dfs(source,destination);
    }
};