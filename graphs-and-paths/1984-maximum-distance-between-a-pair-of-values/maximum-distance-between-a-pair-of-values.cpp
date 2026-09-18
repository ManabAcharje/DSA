class Solution {
public:
    int binarySearch(int low,int high,int val,vector<int>&nums){
        
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=val){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        bool valid=false;
        int ans=(INT_MIN);
        for(int i=0;i<n1;i++){
            int j=binarySearch(i,n2-1,nums1[i],nums2);
            if(j!=-1){
                valid=true;
                ans=max(ans,j-i);
            }
        }
        return valid?ans:0;
    }
};