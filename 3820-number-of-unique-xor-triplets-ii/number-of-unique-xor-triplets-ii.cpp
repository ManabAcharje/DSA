class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max_xor = 2048;
        vector<bool>possible_xor(max_xor,false);
        vector<bool>temp(max_xor,false);
        size_t n = nums.size();
        for(int i  =0 ; i<n;i++){
            for(int j = i; j<n ;j++){
                temp[nums[i]^nums[j]]=true;
            }
        }
        for(int x=0; x<max_xor;x++) {
            if(temp[x]==false)continue;
            for(int v: nums){
                possible_xor[x^v]=true;
            }
        }
        int count = 0;
        for(bool x : possible_xor){
            if(x== true)count++;
        }
        return count;
    }
};