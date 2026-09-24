class Solution {
    public int smallestIndex(int[] nums) {
        int i = -1;
        for(int num: nums){
            int sum = 0;
            i++;
            while(num > 0){
                sum+=(num%10);
                num/=10;
            }
            if(sum == i)return i;
        }
        return -1;
    }
}