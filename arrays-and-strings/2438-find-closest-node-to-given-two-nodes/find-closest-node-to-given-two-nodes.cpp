class Solution {
public:
    int n;
    vector<bool>visited;
    void dfs(int node,int d,vector<int>& edges, vector<int> &dist){
        
        visited[node]=true;
        
        dist[node]=d;
        if(edges[node]==-1)return;
        if(!visited[edges[node]])
            dfs(edges[node],d+1,edges,dist);
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         n=edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        int ans=INT_MAX;
        int idx=-1;

        visited.assign(n,false);

        dfs(node1,1,edges,dist1);

        visited.assign(n,false);
        dfs(node2,1,edges,dist2);


        for(int i=0;i<n;i++){

            int curr=max(dist1[i],dist2[i]);
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;
            if(ans>curr){ans=curr;idx=i;}
        }
        return idx;
    }
};