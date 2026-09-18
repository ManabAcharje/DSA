class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int max_range = 0;
        int sum = 0;
        for(int num : nums){
            string s = to_string(num);
            sort(s.begin(),s.end());
            int largest = s.back()-'0';
            int smallest = s[0]-'0';
            int curr_range= largest -smallest;
            if(curr_range == max_range)sum+=num;
            else if(curr_range>max_range){
                sum = num;
                max_range=curr_range;
            }
        }
        return sum;
    }
};