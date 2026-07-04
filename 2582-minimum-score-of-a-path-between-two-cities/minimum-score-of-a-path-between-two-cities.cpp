class Solution {
public:
    unordered_map<int, vector<pair<int,int>>>adj;
    vector<bool>visited;

    int min_d;

    void dfs(int node){
        visited[node] = true;
        for(auto &[v,wt]:adj[node]){
            min_d = min (min_d, wt);
            if(!visited[v]){
                dfs(v);
                
            }

        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        //min paht 
        // it will be the the min weight of the edge in the component where node 1 is present

        //so dfs on node one and track the min edge
        // unordered_map<int, vector<pair<int,int>>> adj;

        // for(auto road: roads){
        //     int u = road[0];
        //     int v = road[1];
        //     int wt = road[2];

        //     adj[u].push_back({wt,v});
        //     // adj[v].push_back({wt,u});

            
        // }
        // //bfs(from node 1);
        // visited.assign(n+1,false);
        // queue<int> q;
        // q.push(1);
        // visited[1]= true;
        // int min_d = INT_MAX;
        // while(!q.empty()){
        //     int u = q.front();
        //     q.pop();
        //     for(auto &[wt,v] : adj[u]){
                
        //         if(!visited[v]){
        //             min_d = min(min_d,wt);
        //             visited[v] = true;
        //             q.push(v);
        //         }

        //     }
           
        // }
        // return min_d;


        for(auto & road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        visited.assign(n+1,false);
        min_d = INT_MAX;
        dfs(1);
        return min_d;
    }
};