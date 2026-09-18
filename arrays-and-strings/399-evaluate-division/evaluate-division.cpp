class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double queryAns;

    bool dfs(string a, string b, double prod) {
        if (adj.find(a) == adj.end() || adj.find(b) == adj.end())
            return false;

        if (a == b) {
            queryAns = prod;
            return true;
        }

        visited[a] = true;

        for (auto  &nbr : adj[a]) {
            string next = nbr.first;
            double wt = nbr.second;

            if (!visited[next]) {
                if (dfs(next, b, prod * wt))
                    return true;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        /*
            equations
            values
            queries

            a->b->c  do it is dfs in directed graph if we can't find then return
           -1;


        */
        
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1.0 / wt});
        }

        vector<double> ans;

        for (auto &query : queries) {
            string dividend = query[0];
            string divisor = query[1];

            visited.clear();
            queryAns = -1.0;

            bool pathFound = dfs(dividend, divisor, 1.0);

            if (pathFound)
                ans.push_back(queryAns);
            else
                ans.push_back(-1.0);
        }

        return ans;
    }
};