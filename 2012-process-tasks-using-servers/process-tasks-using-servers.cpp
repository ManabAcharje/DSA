
typedef pair<int,int> P;
typedef pair<int,P> PP;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P,vector<P>,greater<P>>minH;
        priority_queue<PP,vector<PP>,greater<PP>>unavail_server;

     
        for(int i = 0 ; i < n ; i++){
            minH.push({servers[i],i});
        }
        long long  curr_time = 0;
        vector<int> ans(m);
        for(int j = 0;  j < m; j++){
            curr_time = max(curr_time , (long long )j);
            if(minH.empty() && !unavail_server.empty()){
                curr_time = max(curr_time , (long long )unavail_server.top().first);
            }
            while (!unavail_server.empty() && unavail_server.top().first <= curr_time) {
                PP top_val = unavail_server.top();
                unavail_server.pop();
                int free_time = top_val.first;
                int wt = top_val.second.first;
                int idx = top_val.second.second;
                minH.push({wt, idx});
            }
            
            P best_server = minH.top();
            minH.pop();
            int wt = best_server.first;
            int idx = best_server.second;
            
            ans[j] = idx;
            unavail_server.push({curr_time + tasks[j], {wt, idx}});
        }
        
        return ans;

    }
};