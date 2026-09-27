class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;

        for(int ch : s)
        {
            st.push(ch);
            if(st.top() ==  ')')
            {
                queue<int>q;
                st.pop();
                while(!st.empty() && st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }   
        }
        string ans = "";
        while(!st.empty()){
            ans+=(char)st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};