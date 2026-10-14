class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if(sum>(9*num))return "";

        StringBuilder ans = new StringBuilder("");
        while(num>0) {
            // System.out.printf("sum = %d num = %d \n",sum,num);
            for(int i = 9 ; i>= 0 ; i--){
                if(sum>=i){
                    ans.append(i);
                    sum-=i;
                    break;

                }
            }
            num--;
        }
        return ans.toString();
    }
}