class Solution {
public:
    bool checkString(string s) {
        int b_count = 0;
        int a_count= 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == 'a'){
                a_count++;
                if(b_count>0)return false;
            }
            else{
                b_count++;
            }
        }
        return true;
    }
};