// public class Tuple<F,M,L>{
//     public final F first;
//     public final M second;
//     public final L third;
//     public Tuple<F first, M second , L third> {
//         this.first = first;
//         this.second = second;
//         this.third = third;
//     } 
// }
class Solution {
    private boolean isSorted(String s){
        int n = s.length();
        for(int i= 1; i < n; i++){
            if(s.charAt(i) < s.charAt(i-1))return false;
        }
        return  true;
    }
    public int minOperations(String s) {
        int n = s.length();
        
        if(s.length() == 1 || isSorted(s))return 0;
        
 
        char mini = 'z'+1;
        System.out.print(mini+" ");
        char maxi = 'a'-1;
        System.out.print(maxi+" ");

        int minPos = -1;
        int maxPos = -1;
        for(int i = 0 ; i  < s.length(); i++){
            char ch = s.charAt(i);
            if(ch < mini){
                mini = ch;
                minPos = i;
            }
            if(ch >= maxi){
                maxi = ch;
                maxPos = i;
            }
        }
        // System.out.print(minPos+" ");
        // System.out.print(maxPos+" ");
        if(n==2 && minPos == 1 && maxPos == 0)return -1;
        
 
        if(minPos == n-1 && maxPos == 0)return 3;
        else if(minPos == 0 || maxPos == n-1)return 1;
        return 2;


        
    }
}



       // dog
        // card
        // car 
        // acrd
        // a(crd) = acdr
        // if the last char is the first character and the first char is last 
        //find smallest char and it pos
        //find largest char and it position
        //if already soted order return 0;
        // if small and large at last and first pos respectively return -1;
        // if any one of them at same pos return 1;
