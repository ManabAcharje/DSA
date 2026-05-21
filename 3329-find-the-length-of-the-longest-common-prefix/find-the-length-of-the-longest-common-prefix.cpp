class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        unordered_set<int>st;
        for(auto &n:arr1){
            while(n){
                st.insert(n);
                n/=10;
            }
        }
        for(auto &n:arr2){
            while(n){
                if(st.count(n)){
                    ans=max(ans,((int)log10(n)+1));
                    
                }
                n/=10;
            
            }
        }
        return ans;

    }
};