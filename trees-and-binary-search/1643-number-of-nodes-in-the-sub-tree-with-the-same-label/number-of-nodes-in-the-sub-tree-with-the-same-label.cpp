class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    vector<vector<int>> freq;

    void dfs(int node, int parent, string &labels){
        
        freq[node][labels[node] - 'a']++; 
        
        for(auto &v: adj[node]){
            if(v != parent){
                dfs(v, node, labels);             
                for(int i = 0; i < 26; i++){
                    freq[node][i] += freq[v][i];
                }
            }
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        ans.resize(n, 0);
        freq.assign(n, vector<int>(26, 0)); 
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, labels);
        
        for(int i = 0; i < n; i++){
            
            ans[i] = freq[i][labels[i] - 'a']; 
        }
        
        return ans;
    }
};