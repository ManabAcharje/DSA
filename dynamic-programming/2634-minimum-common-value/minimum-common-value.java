class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n1=nums1.length;
        int n2=nums2.length;
        if(n1>n2)return getCommon(nums2, nums1);
    
        for(int i=0;i<n1;i++){
            int num=nums1[i];
            int low=0;
            int high=n2-1;
            while(low<=high){
                int mid=low+(high-low)/2;

                if(nums2[mid]==num)return num;
                else if(nums2[mid]>num)high=mid-1;
                else low=mid+1;
            }
            
        }
        return -1;
    }
}