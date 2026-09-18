class Solution {
public:
    vector<vector<int>> result;
    vector<bool>visited;
    int n;
    void dfs(int node,vector<int>& temp,vector<vector<int>>& adj){
        if(node==n-1){result.push_back(temp);return; }
        // visited[node]=true;
        for(auto &ngbr: adj[node]){
            if(!visited[ngbr]){
                temp.push_back(ngbr);
                // visited[ngbr]=true;
                dfs(ngbr,temp,adj);
                temp.pop_back();
                // visited[ngbr]=false;
            }


        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        n=adj.size();
        visited.resize(n,false);
        vector<int>temp;
        temp.push_back(0);
        dfs(0,temp,adj);
        return result;    
    }
};