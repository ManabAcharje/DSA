class Solution {
public:
    bool bfs(int node,vector<int>& colors,int currColor,unordered_map<int,vector<int>>& adj){
        queue<int>q;
        colors[node]=currColor;
        q.push(node);

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int &v:adj[u]){
                if(colors[v]==colors[u])return false;
                else if(colors[v]==-1){
                    colors[v]=1-colors[u];
                    
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //it is saying to check biparatae or not 
        
        unordered_map<int,vector<int>>adj;
        for(auto &dislike:dislikes){
            int u=dislike[0];
            int v=dislike[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>colors(n+1,-1);

        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
                if(bfs(i,colors,0,adj)==false)return false;

            }
        }
        return true;

    }
};