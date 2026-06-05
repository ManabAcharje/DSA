class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // equal rows or complementary rows is the total ans;
         // 1 0 1 0 1 0
         // 1 1 1 0 0 0 
         // 0 0 0 1 1 1 
         // 1 1 1 0 0 0 
         // 0 1 0 1 0 1 
         // 0 1 0 1 0 1
         // 1 0 1 0 1 0 

         //xor ==0 || & ==0 
         // loop for each row find keep a count of 

         int ans=0;
         int n=matrix[0].size();

        unordered_map<string,int> freq;
        for(auto &row:matrix){
            string key="";
            string compKey="";
            for(int col =0 ;col<n;col++){
                key+=row[col]+'0';
                compKey+=(1-row[col])+'0';
            }
            freq[key]++;
            freq[compKey]++;
            ans= max({ans,freq[key],freq[compKey]});
        }
        return ans;

    }
};