class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n  = nums.size();
        if(n <= 1)return n;
        int count = 0;
        int i = 0;
        while(i < n){
            bool left_exist = i>=1;
            bool right_exist = i<=n-2;
            double avg;
            if(left_exist && right_exist){
                avg = (nums[i-1])/2.0 + nums[i+1]/2.0;
            }else if(!right_exist){
                avg = nums[i-1];
            }else{
                avg = nums[i+1];

            }
            if(avg <= (double)nums[i]){
                count++;
            }
            cout<<count<<" ";
            i++;
        }
        return count;
    }
};