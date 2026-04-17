class Solution {
public:
    int maxDistinct(string s) {
        set<int>st;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(!st.count(s[i]))count++;
            st.insert(s[i]);
        }
        return count;
    }
};