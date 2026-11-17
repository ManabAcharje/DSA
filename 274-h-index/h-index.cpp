class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 6or more  ->1
        // 5 or more  -> 1 + 1
        // 4 or more ->2
        // 3 or more -> 
        vector<int>freq(10001,0);
        for(int cite : citations){
            freq[cite]++;
        }
        int ans = 0;
        for(int i = 10000 -1; i >= 0; i--){
                freq[i]= freq[i+1] + freq[i];
                if(freq[i] >= i) return i;
        }
        return ans;
    }
};