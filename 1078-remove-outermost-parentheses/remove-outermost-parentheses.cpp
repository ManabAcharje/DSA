class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string ans = "";
        for (char ch : s) {
            if (ch == '(') {
                
                if (balance == 0) {
                    balance++;
                    continue;
                } else {
                    balance++;
                    ans.push_back(ch);
                    
                }
            } else {
                if (balance == 1) {
                    balance--;
                    continue;
                } else {
                    balance--;
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};