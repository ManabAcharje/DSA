class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        if(n < m)return false;
        int i = 0 ,  j = 0;
        while(i < m && j < n){
            if(name[i] == typed[j]){
                i++;
                j++;
            }else if(name[i] != typed[j]){
                if(j==0)return false;
                else if( typed[j] == typed[j-1]){
                    j++;
                }else{
                    return false;
                }
            }   
        }
        if(j == n  && i != m)return false;
        for(; j < n; j++){
            if(typed[j] != typed[j-1]){
                return false;
            }
        }
        return true;
    }
};