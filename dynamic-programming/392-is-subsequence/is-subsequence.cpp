class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0;int j=0;
        while(i<n && j <m){
            if(t[j]==s[i]){
                i++;
                j++;



            }
            else j++;
        }
        if(i==n)return true;
        return false;
    }
};