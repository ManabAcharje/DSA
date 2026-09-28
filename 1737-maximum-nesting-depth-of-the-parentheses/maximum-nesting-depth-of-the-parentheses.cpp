class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int result = 0;
        for(char ch : s){
            if(ch == '(')
                ans++;
            result = max(ans,result);
            if(ch == ')')ans--;
        }
        return result;
    }
};