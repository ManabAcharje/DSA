class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        int n = nums.size();
        vector<int>visited (51,0);
        visited[nums[0]]=1;
       
        while(i<n && nums[i-1]+1 == nums[i]){
            sum+=nums[i];
            visited[i] = 1;
          
            i++;



            
        }
        for(i = 1 ;i<n;i++){
            visited[nums[i]]=1;
           
        }
        
        while(sum<51 && visited[sum])sum++;
        return sum;

        //now from sum upuntil values i have seen need to be skip
        //question did i see sum if yes then did i see sum +1 and so on;
        //if i didn't see sum then 
    }
};