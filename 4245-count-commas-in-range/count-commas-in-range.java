class Solution {

    
    public int countCommas(int n) {

        int comma = 0;
        for(int i =1000;i<=n;i++){
            if(i>=1000 && i< 1000000)comma++;
        }
        return comma;

    }
}