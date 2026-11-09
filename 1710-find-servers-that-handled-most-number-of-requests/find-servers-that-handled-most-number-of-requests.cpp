class Solution {
public:
    // first (i % k ) -> if it is busy -> check next_not busy server-> if all
    // bussy ->discard this task - > there for i need to track servers status
    // curr_time and server_will have their reset time
    // so if it is less than curr time it can be assigned
    // but checking all one by one can take o(n) time for each assignment
    // therefore  we need to store for each index -> what is the next available
    // server now question becomes max log(n) query update and log(n) query
    // fetch we can getthat using segment tree;

    struct SegTree{
        int n ;
        vector<int>tree;
        SegTree(int n ): n(n), tree(4*n,0){
            build(1,0,n-1);
        }
        void build(int node , int l , int r){
            if(l==r){
                tree[node] = 1;
                return;
            }
            int mid = (l + r)/2;
            build(2*node  , l , mid);
            build(2*node + 1, mid + 1 , r);
            tree[node] = tree[2*node] + tree[2*node + 1];

        }
        void update (int node , int l , int r, int idx , int val){
            if(l == r){
                tree[node] = val ;
                return ;
            }
            int  mid = (l + r)/ 2;

            if(idx <= mid) update(2*node , l , mid , idx, val);
            else update(2*node + 1, mid + 1 , r , idx, val);
            tree[node] = tree[2*node] + tree[2*node + 1];
        }
        int queryFirst (int node , int l , int r, int ql , int qr){
            if(l > qr || r< ql || tree[node] == 0 ) return -1;
            if(l == r)return l ; 
            int mid = (l + r)/ 2;
            int left = queryFirst (2*node , l , mid , ql,qr);
            if(left != -1 )return left;
            return queryFirst(2*node + 1, mid + 1, r, ql , qr);
        }
    };

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        SegTree segTree(k);
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy_pq;
        

        vector<int>server_count(k, 0);
        for (int i = 0; i < n; i++) {
            // now this ith task will be assigned to next available server
            long long curr_time = arrival[i];

            while (!busy_pq.empty() && busy_pq.top().first <= curr_time) {
                int s_id = busy_pq.top().second;
                busy_pq.pop();
                segTree.update(1, 0, k - 1, s_id, 1);
            }
            if (segTree.tree[1] == 0)
                continue;
            int target = i % k;
            int assigned_server = -1;
            assigned_server = segTree.queryFirst(1, 0, k - 1, target, k - 1);
            if (assigned_server == -1) {
                assigned_server =
                    segTree.queryFirst(1, 0, k - 1, 0, target - 1);
            }
            if (assigned_server != -1) {
                segTree.update(1, 0, k - 1, assigned_server, 0);
                busy_pq.push({curr_time + load[i], assigned_server});
                server_count[assigned_server]++;
            }
        }
        int max_task_assigned = 0;
        for (int j = 0; j < k; j++) {
            if (server_count[j] > max_task_assigned) {
                max_task_assigned = server_count[j];
            }
        }
        vector<int> busiest_servers;
        for (int j = 0; j < k; j++) {
            if (server_count[j] == max_task_assigned)
                busiest_servers.push_back(j);
        }
        return busiest_servers;
    }
};