class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int total=0;
        int n=cost.length;
        if(n==1)return cost[0];
        int j=n-1;
        while(j>=2){
            total+=(cost[j]+cost[j-1]);
            j-=3;

        }
        for(int i=0;i<=j;i++){
            total+=cost[i];
        }
        return total;
    }
}