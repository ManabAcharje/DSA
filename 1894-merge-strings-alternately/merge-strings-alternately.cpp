class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size();
        int  n=word2.size();
        string ans="";
        int i=0,j=0;
        while(i<m && j<n){
            string temp="";
            temp+=word1[i];temp+=word2[j];
            ans+=temp;
            i++;j++;
        }
        while(i<m){ans+=word1[i++];}
        while(j<n){ans+=word2[j++];}
        return ans;

    }
};