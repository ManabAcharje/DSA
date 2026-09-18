class Solution {
    int m,n;
    String s, t;
    int dp[][];
    int solve(int i, int j){
        if(i==m || j == n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int opt1=0;
        if(s.charAt(i)==t.charAt(j)){opt1 = 1 + solve(i+1, j+1);}
        
        int opt2 = Math.max(solve(i+1,j), solve(i,j+1));

        return dp[i][j]= Math.max(opt1,opt2);
    }
    public int longestCommonSubsequence(String text1, String text2) {
        // 2 string given  max subsequece in a su try selecing all subsequence;
        // 
        dp = new int [1001][1001];
        for(int i=0;i<1001;i++){
            for(int j =0 ; j< 1001 ; j++){
                dp[i][j]= -1;
            }
        }
        m = text1.length();
        n = text2.length();

        this.s= text1;
        this.t= text2;

        return solve(0,0);




    }
}