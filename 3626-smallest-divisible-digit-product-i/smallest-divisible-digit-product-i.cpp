class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int  i = n ; i<=100 ; i++){
            int prod = 1;
            int copy = i;
            while(copy){
                int r = copy%10;
                prod *= r;
                copy = copy/10;
            }
            if(prod % t ==0 )return i;
        }
        return -1;
    }
};