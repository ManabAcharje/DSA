class Solution {
    public boolean checkDivisibility(int n) {
        int x = n;
        int digit_product= 1,digit_sum = 0;
        while(n>0){
            int rem = n%10;
            digit_sum +=(rem);
            digit_product *= rem;
            n/=10;
        }
        return x%(digit_sum+digit_product)==0? true: false;
    }
}