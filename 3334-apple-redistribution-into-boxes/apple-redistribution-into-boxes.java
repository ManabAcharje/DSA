class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        
        Arrays.sort(capacity);
        int total=0;
        for(int i=0;i<(int)apple.length;i++){
            total+=apple[i];
        }
        int n=capacity.length;
        for(int i=n-1;i>=0;i--){
            total-=capacity[i];
            if(total<=0)return n-i;
        }
        return -1;
    }
}