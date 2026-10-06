class Solution {
public:
    int minAddToMakeValid(string s) {

        // stack<int>st;
        // for(int ch : s){
        //     if(ch == '('){
        //         st.push('(');
        //     }
        //     else{
        //         if(!st.empty() && st.top() == '('){
        //             st.pop();
        //         }
        //         else st.push(ch);
        //     }
        // }
        

        // return st.size();
        int balance = 0;
        int ans  = 0;
        for(char &ch : s){
            if(ch == '('){
                balance++;
            }
            else{
                balance --;
                if(balance < 0){
                    ans++;
                    balance++;
                }
            }
        }
        return ans+balance;
    }
};