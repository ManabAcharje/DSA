class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        // x1 + x2 + x3...  + xn == sum
        //max score take bigger no
        //                    
        if(sum>( 9 * n))return "";
        string ans = "";
        while(n){
            int score = 0;

            for(int i = 9  ; i>=0; i--){
                if(sum>=i){
                    sum-=i;
                    ans+=(i+'0');
                    score+=(i*i);
                    break;

                }
            }
            n--;
            
        }
        return ans;
    }
};