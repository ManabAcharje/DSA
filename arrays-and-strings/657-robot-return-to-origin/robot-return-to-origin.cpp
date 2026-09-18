class Solution {
public:
    int returnVal(char a){
        if (a=='R')return 1;
        else if(a=='L')return -1;
        else if(a=='U')return 2;
        else return -2;
    }
    bool judgeCircle(string moves) {
        int n=moves.size();
        int first_sum=0;
        int second_sum=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='R'||moves[i]=='L'){
                first_sum+=returnVal(moves[i]);
            }
            else{second_sum+=returnVal(moves[i]);
            }
                


        }
        return(first_sum==0 && second_sum==0);
    }
};