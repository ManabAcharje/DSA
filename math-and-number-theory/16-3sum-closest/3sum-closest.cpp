class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int min_diff=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int curr=nums[i]+nums[j]+nums[k];
                    int curr_diff;
                    if(curr>=target){
                        curr_diff=(curr-target);
                    }
                    else{
                        curr_diff=(target-curr);
                        
                    }
                    if(curr_diff < min_diff){
                        min_diff =curr_diff;
                        ans=curr;
                    }
                }
            }
            
        }
        return ans;
    }
};