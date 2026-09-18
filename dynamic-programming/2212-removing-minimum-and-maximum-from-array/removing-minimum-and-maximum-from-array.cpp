class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n  = nums.size();
        // cout<<n<<"\n";
        if(n==1)return 1;
        int minIdx = 0;
        int maxIdx = 0;

        int mini= INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i< n;i++){
            if(nums[i]<mini){

                mini = nums[i];
                minIdx= i;

            }
            if(nums[i]>maxi){
                maxi =  nums[i];
                maxIdx = i;
            }
        }
        // cout<<maxIdx<<" "<<minIdx;
        if(maxIdx<minIdx){
            // cout<<"here";
            return min({minIdx+1,n-maxIdx,n-minIdx+maxIdx+1});
        }
        else{//minIdx<maxIdx
            // cout<<"there";
            // cout<<maxIdx+1<<" "<<n-minIdx<<" "<<n+minIdx-maxIdx+1;
            return min({maxIdx+1,n-minIdx,n+minIdx-maxIdx+1});
        }

        // n-maxIdx + minIdx+1


    }
};


