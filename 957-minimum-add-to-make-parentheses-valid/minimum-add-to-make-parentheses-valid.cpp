class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.top()!=')')
                    st.pop();
                else{
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};