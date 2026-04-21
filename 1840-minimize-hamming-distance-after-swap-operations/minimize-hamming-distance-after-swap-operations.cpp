class Solution {
public:
    int n;
    vector<int> parent, rank;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb) return;

        if(rank[pa] < rank[pb])
            parent[pa] = pb;
        else if(rank[pb] < rank[pa])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& arr) {
        n = source.size();

        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        // Step 1: build DSU
        for(auto &e : arr) {
            Union(e[0], e[1]);
        }

        // Step 2: group indices
        unordered_map<int, unordered_map<int,int>> mp;

        for(int i = 0; i < n; i++) {
            int p = find(i);
            mp[p][source[i]]++;   // count source values per component
        }

        // Step 3: match target
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int p = find(i);

            if(mp[p][target[i]] > 0) {
                mp[p][target[i]]--;   // match found
            } else {
                ans++;  // mismatch
            }
        }

        return ans;
    }
};