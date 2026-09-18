class Solution {
public:
    int maxProduct(int n) {
        int fm = -1;
        int sm= -1;
        while(n){
            int r = (n%10);
            if(r>=fm){sm = fm; fm = r;}
            else if ( r>sm )sm= r;
            n/=10;

        }
        return fm*sm;
    }
};