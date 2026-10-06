class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<int>st;
        for(int ch : s){
            if(ch == '('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else st.push(ch);
            }
        }
        

        return st.size();
    }
};