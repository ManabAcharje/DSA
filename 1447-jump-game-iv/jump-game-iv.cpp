class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);

        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0] = true;

        while(!q.empty()) {
            auto [u, steps] = q.front();
            q.pop();

            if(u == n - 1) return steps;

            
            if(u - 1 >= 0 && !visited[u - 1]) {
                visited[u - 1] = true;
                q.push({u - 1, steps + 1});
            }

         
            if(u + 1 < n && !visited[u + 1]) {
                visited[u + 1] = true;
                q.push({u + 1, steps + 1});
            }

    
            for(int v : mp[arr[u]]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, steps + 1});
                }
            }
            mp[arr[u]].clear();
        }

        return -1;
    }
};