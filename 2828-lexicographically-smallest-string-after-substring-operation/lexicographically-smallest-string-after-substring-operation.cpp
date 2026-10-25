class Solution {
public:
    string smallestString(string s) {
        //find the unsorted portion  from the begining
        int i = 0;
        int n= s.size();
        while(i < n  && s[i] == 'a')i++;

        if(i ==  n ){
            s.back() = 'z';
            return s;
        }
        while(i < n && s[i]!='a'){
            s[i] = 'a' + (s[i]-'a' - 1 + 26) %26 ; 
            i++;
        }
        return s;
        
    }
};