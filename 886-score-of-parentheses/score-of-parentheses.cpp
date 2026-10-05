class Solution {
public:
    int scoreOfParentheses(string s) {
        string ss =  "";
        for(char ch: s){
            if(ch == '('){
                ss+= ch;

            }
            else{
                if(!ss.empty() && ss.back()== '('){
                    ss.pop_back();
                    ss+=1;
                }else{
                    ss+=')';
                }
            }
        }
        int score = 0;
        int depth = 0;
        for(char ch : ss){
            if(ch == '('){
                depth ++;
            }
            else if(ch == ')'){
                depth--;
            }
            else{
                score += (1<<depth);
            }
        }
        return score;
    }
};