class Solution {
    public long maximumValue(int n, int s, int m) {
       if(n== 1)return s;
       return (long)s + m + (n/2-1L)*(m-1);
    
       

       
        
        
        // 6 13 12 19  18 25 24 


        // 6  12  18 24
        // 13 19  25 31
        // odd hoile starting from 6
        // even hoi

    }
}