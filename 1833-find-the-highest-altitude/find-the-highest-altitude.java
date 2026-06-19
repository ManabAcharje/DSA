class Solution {
    public int largestAltitude(int[] gain) {
        int altitude=0;
        int maxAlt=0;
        for(int g:gain){
            altitude=altitude+g;
            maxAlt=Math.max(altitude,maxAlt);
        } 
        return maxAlt;
    }
}