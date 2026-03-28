class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            rank[x_parent]++;
            parent[y_parent] = x_parent;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool equationsPossible(vector<string>& equations) 
    {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (auto &s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for (auto &s : equations) {
            if (s[1] == '!') {
                int first = find(s[0] - 'a');
                int second = find(s[3] - 'a');

                if (first == second)
                    return false;
            }
        }
        return true;
    }
};