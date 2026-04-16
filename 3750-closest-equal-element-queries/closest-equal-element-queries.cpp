class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        
        unordered_map<int,vector<int>>mp;
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &[val,pos]:mp){
            int k=pos.size();
            if(k==1)continue;
            for(int i=0;i<k;i++){
                int curr=pos[i];
                int prev=pos[(i-1+k)%k];
                int next=pos[(i+1) % k];

                int d1=abs(next-curr);
                int d2=abs(curr-prev);

                d1=min(d1,n-d1);
                d2=min(d2,n-d2);

                ans[curr]=min(d1,d2);

            }
        }
        for(int i=0;i<queries.size();i++){
            queries[i]=ans[queries[i]];
        }
        return queries;


    }
};