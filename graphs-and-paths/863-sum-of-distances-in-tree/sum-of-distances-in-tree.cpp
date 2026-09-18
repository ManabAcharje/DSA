class Solution {
public:
    unordered_map<int,vector<int>>adj;

    vector<int> subtreeSize;
    vector<int> ans;
    int n;
    void dfs1(int node, int parent,int depth){
        ans[0] += depth;
        subtreeSize[node] = 1;

        for (int child : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node, depth + 1);

            subtreeSize[node] += subtreeSize[child];
        }
    }
    void dfs2(int node,int parent){
         for (int child : adj[node]) 
         {
            if (child == parent) continue;

            ans[child] =
                ans[node] - subtreeSize[child] + (n - subtreeSize[child]);

            dfs2(child, node);
        }
    }


    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        subtreeSize.resize(n);
        ans.resize(n, 0);

        dfs1(0,-1,0);
        dfs2(0,-1);
        return ans; 
    }
};
/*
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>dist(n,-1);
        unordered_map<int,vector<int>>adjList;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> result(n,0);

        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            int ans=0;
            queue<pair<int,int>>q;
            q.push({i,0});
            visited[i]=true;
            while(!q.empty()){
                auto [u,t]=q.front();
                q.pop();
                ans+=t;
                for(int &v:adjList[u]){
                    if(!visited[v]){
                        q.push({v,t+1});
                        visited[v]=true;
                    }
                }

            }
            result[i]=ans;

        }
        return result;


           
    }
};
*/