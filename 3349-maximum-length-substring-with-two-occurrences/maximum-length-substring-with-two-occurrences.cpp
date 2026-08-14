class Solution {
public:
    int maximumLengthSubstring(string s) {
        //max 2 occurances of each;

        vector<int> freq (26,0);
        int n = s.size();
        int maxLen = 0;
        int i = 0;
        for(int j = 0 ; j< n;j++){
            int x  = s[j] - 'a';
            freq[x]++;
            if(freq[x]>2){
                maxLen = max(j-i,maxLen);
                while(freq[x]!=2){
                    freq[s[i]-'a']--;
                    i++;
                }
            }
            else{
                maxLen = max(j-i+ 1 , maxLen);
            }

        }
        return maxLen;
    }
};