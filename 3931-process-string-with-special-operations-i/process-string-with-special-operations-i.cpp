class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char ch : s) {
            if(ch>='a' && ch<='z'){
                result+=ch;
            }
            else if(ch == '*'){
                if(result.size()>=1)
                result.pop_back();
            }
            else if(ch=='#'){
                if(result.size()>=1)
                result+=result;
            }
            else{
                if(result.size()>=1)
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};