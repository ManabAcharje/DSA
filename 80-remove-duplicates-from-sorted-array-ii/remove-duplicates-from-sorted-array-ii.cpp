class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  n = nums.size();
        int i = 0;
        int j  = 0;
        int count = 1;

        while(j < n){
            count = 1; 
            while(j + 1  < n && nums[j+1] == nums[j]){
                count++;
                j++;

            }
            int x = nums[j];
            for(int k = 0 ; k < min(count,2); k++){
                nums[i++] = x;
            }
            j++;
        }
        // cout<<nums[j-1] << " "<<count<<endl
        return i;
    }
};