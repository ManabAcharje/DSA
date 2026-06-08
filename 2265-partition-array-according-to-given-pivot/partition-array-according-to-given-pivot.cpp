class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lesser = 0;
        int higher = 0;
        int equal = 0;

        int n = nums.size();

        for (int num : nums) {
            if (num < pivot) {
                lesser++;

            } else if(num == pivot){
                    equal++;
            } else {
                higher++;
            }
        }
        vector<int> ans(nums.size());
        int lessIdx = 0;
        int equalIdx = lesser;
        int greaterIdx = lesser + equal;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < pivot) {
                ans[lessIdx++] = num;


            } else if (num > pivot) {
                ans[greaterIdx++]=num;
            } else {
                ans[equalIdx++] = num;
                
            }
        }
        return ans;
    }
};
/*
    9 12 5 10 14 3 10
    9 10 5 12 14 3 10
    9 5 10 12 14 3 10
    9 5 10 12 14 3 10
    9 5 3  12 14 10 10

    9 12 5 10 14 3 10
    9 10 5 10 14 3 12
    9 3 5 10 14 10 12
    9 3 5 10 10 14 12

    if nums< pivot  place at left
    if nums>= pivot place ar right



*/