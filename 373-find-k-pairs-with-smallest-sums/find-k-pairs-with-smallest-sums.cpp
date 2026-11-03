class Solution {
public:
    typedef pair<int,pair<int , int> > P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;

        set<pair<int,int>> visited;
        vector<vector<int>> ans;

        priority_queue<P,vector<P> ,greater<P>> minH;
        minH.push({nums1[0]+ nums2[0],{0,0}});
        visited.insert({0,0});

        while(k > 0 && !minH.empty()){
            auto top = minH.top();
            minH.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i],nums2[j]});
            k--;
            if(i + 1 < m && !visited.count({i+1,j})){
                visited.insert({i+1,j});
                minH.push({nums1[i+1] + nums2[j] , {i+1,j}});
            }
            if(j + 1 < n && !visited.count({i,j+1})){
                visited.insert({i,j+1});
                minH.push({nums1[i] + nums2[j+1] , {i,j+1}});
            }
        }
        return ans;



        

        


        
    }
};