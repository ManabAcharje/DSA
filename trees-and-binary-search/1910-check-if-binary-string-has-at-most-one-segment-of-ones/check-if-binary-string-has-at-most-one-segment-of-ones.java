class Solution {
    public boolean checkOnesSegment(String s) {
        boolean prev_zero = false;
        for(int  i = 0 ; i< s.length() ; i++){
            if(s.charAt(i) == '1')
            {
                if(prev_zero){
                    return false;
                }
               
            } 
            else{
                prev_zero = true;
            }
        }
        return true;
    }
}