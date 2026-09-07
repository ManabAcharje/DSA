class Solution {
    public int distinctSubseqII(String s) {
        int n  = s.length();

        int mod = 1000000000+7;

        int [] last_seen = new int[26];
        Arrays.fill(last_seen,-1);
        long []dp = new long[n+1];

        dp[0] = 1;


        for(int i = 1 ; i<= n;i++){
            int ch = s.charAt(i-1) -'a';

            dp[i] =( dp[i-1]*2+mod)%mod;

            if(last_seen[ch]!=-1){
                dp[i] = (dp[i] - dp[last_seen[ch]-1]+mod)%mod;

            }
            last_seen[ch] = i;

        }

        return ((int)dp[n]-1+mod)%mod;


        
    }
}