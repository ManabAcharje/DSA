class Solution {
public:
    vector<vector<int>>rooms;
    vector<int>visited;
    void bfs(int node){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int room=q.front();
            q.pop();
            
            for(int &key:rooms[room]){
                if(!visited[key]){
                    q.push(key);
                    visited[key]=1;

                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        this->rooms=rooms;

        visited.resize(n,0);
        bfs(0);
        for(int x:visited){
            if(!x)return false;
        }
        return true;
    }
};