class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suff(n);
        suff[n-1] = nums[n-1];

        for(int i = n-2 ; i>=0 ; i--){
            suff[i] = min(nums[i],suff[i+1]);
        }
        // for(int i = 0 ;i<n;i++){
        //     cout<<suff[i]<<" ";

        // }
        // cout<<endl;

        int maxi = nums[0];
        for(int i = 0 ; i<n;i++){
            // cout<<"for idx i: ";

            maxi = max(nums[i],maxi);
            // cout<<" maxi = "<<maxi<<" ";
            
           int  mini = suff[i];
        //    cout<<" mini = "<<mini<<endl;
        //    cout<<" maxi - mini = "<<maxi - mini<<endl;
            if(maxi-mini <=k )return i;

        }
        return -1;
    }
};