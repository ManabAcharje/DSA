class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int i = 1;
        for(int x : nums){
            // cout<<i<<endl;
            // cout<<n<<endl;

            // if(i == 0){
            //     i=1;
            //     continue;
            // }
            if((n%i)== 0){
                // cout<<"here"<<endl;
                sum +=(x*x);
            }
            // cout<<sum<<endl;
            // cout<<endl;
            i++;

        }
        return (int) sum;
    }
};