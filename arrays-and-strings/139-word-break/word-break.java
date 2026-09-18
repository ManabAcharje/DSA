class Solution {
    int n;
    Set<String>seen;
    Boolean dp[];
    boolean  solve(int i,String s){
        if (i==n)return true;
        if(dp[i] != null )return dp[i];
        for(int  j  = i ; j < n ; j++){
            if(seen.contains(s.substring(i,j+1))){
                boolean found_right= solve(j+1,s);
                if(found_right){
                    return dp[i] = true;
                }
            }

        }
        return  dp[i] = false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        //word break
        //all possible breaks;
        //applepenapple , apple+pen:
        dp = new Boolean[301];
        n = s.length();
        seen = new HashSet<>();
        for(String word : wordDict){
            seen.add(word);
        }
        return solve(0,s);



        
        
    }
}