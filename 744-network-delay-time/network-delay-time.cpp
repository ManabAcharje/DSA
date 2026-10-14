class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int> visited(n,false);
        
        for(auto t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v,w});
        }

        vector<int> min_time(n+1, INT_MAX);

        queue<pair<int,int>> q;
        q.push({k,0});
        min_time[k] = 0;

        while(!q.empty()){
            auto [curr_node , curr_time] = q.front();
            q.pop();

            for(auto [ngbr , wt] : adj[curr_node]){
                if(curr_time + wt < min_time[ngbr]){
                    min_time[ngbr] = curr_time + wt;
                    q.push({ngbr, curr_time + wt});
                }
            }
        }
        int ans = 0;
        for(int  i = 1 ; i<= n ; i++){
            if(min_time[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,min_time[i]);
        }
        return  ans;

    }
};