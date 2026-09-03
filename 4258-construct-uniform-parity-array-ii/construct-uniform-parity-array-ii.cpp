class Solution {
public:
   
    bool uniformArray(vector<int>& nums) {
        int n  = nums.size();
        
        int smallestOdd = INT_MAX-1  ;

        for(int num: nums){
            if(num<smallestOdd && (num&1))smallestOdd = num;
           
        }
        // cout<<"smallest odd: "<<smallestOdd<<"\n";


        // try to make all even ;
        bool allEven = true;
        for(int i = 0 ;i<n ;i++){
            if(nums[i] &1){//odd 
                if(nums[i] == smallestOdd){
                    allEven = false;
                    break;
                }
            }
        }
        // cout<<allEven<<"\n";
        if(allEven)return true;


        // make allOdd
        bool allOdd = true;
        for(int i= 0;i<n;i++)
        {
            if(nums[i]%2 == 0)
            { //even
                if(smallestOdd>nums[i])
                {// needs a odd lessthan even
                    allOdd = false;
                    break;
                }
            }
        }
        // cout<<allOdd<<endl;
        return allOdd;
    }
};