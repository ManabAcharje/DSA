class Solution {
public:
    unordered_map<int,vector<int>>adjList;

    vector<bool>visited;

    bool dfs(int u,vector<int>&arr){
        visited[u]=true;

        if(arr[u]==0)return true;
        for(auto &v: adjList[u]){
            if(!visited[v]){
                if(dfs(v,arr))return true;
                
            }
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        visited.assign(n,false);
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==0)continue;
            if(i+arr[i]<n)adjList[i].push_back(i+arr[i]);
            if(i-arr[i]>=0)adjList[i].push_back(i-arr[i]);

        }
        return dfs(start,arr);
    }
};