class Solution {
public:
    int LSB(int num){
        int lsb = 32;
        for(int i = 0 ; i< 32 ; i++){
            if(num & (1<<i)){
                lsb = i;
                break;
            }
           
        }
        return lsb;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int xor_val = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            xor_val^=nums[i];
        }
        int lsb = 1 << LSB(xor_val);
        // cout<<lsb<<endl;
        
        int num1 = 0;
        int num2 = 0;
        for(auto &num : nums){
            if(num & lsb){
                // cout<<num<<" : one "<<endl;
                num1^=num;
            }else{
                // cout<<num<<" : two "<<endl;
                num2^=num;

            }

        }
        return{num1,num2};

    }
};