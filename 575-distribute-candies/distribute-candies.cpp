class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        int count = 0,n = nums.size();
                sort(nums.begin(),nums.end());
        int diff=1;
        for(int x : nums){
            cout<<x<<" ";
        }
        cout<<endl;

        for(int i =1; i<nums.size();i++){
            if(nums[i]!=nums[i-1])diff++;
        }
        
        cout<<diff;
        
        return min(diff,n/2);

    }
};