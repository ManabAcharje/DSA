class NumArray {
public:
    vector<int>v;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            v.push_back(v.back()+nums[i]);

        }
    }
    
    int sumRange(int left, int right) {
        return v[right]-(left==0?0:v[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */