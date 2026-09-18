class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int j=0;j<s.size();j++){
            for(int i=0;i<s.size()-1;i++){
                char temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
            if(s==goal)return true;
        }
        return false;
    }
};