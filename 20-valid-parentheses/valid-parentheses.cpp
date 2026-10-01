class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
                // cout << "pushed " << c << endl;
            } else {
                if (st.empty())
                    return false;
                if (c == ')' && st.top() == '('){

                    // cout<<"popped "<<st.top();
                    st.pop();
                    continue;
                }
                if (c == '}' && st.top() == '{')
                {

                    // cout<<"popped "<<st.top();
                    st.pop();
                    continue;
                }

                if (c == ']' && st.top() == '['){
                    // cout<<"popped "<<st.top();
                    
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        return st.size() == 0;
    }
};