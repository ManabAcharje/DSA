class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int minProd= nums[0];
      
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int x=nums[i];

            if(x<0){
                swap(minProd,maxProd);
            }
            
            maxProd=max(x,maxProd*x);
            minProd=min(x,minProd*x);

            ans=max(maxProd,ans);
        }
        return ans;
    }
};