class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        int ans = 0;

        for (int j = 0; j < n - 1; j++) {
            unordered_map<int, int> left;
            int left_distinct = 0;
            vector<int> freq(26, 0);
            for (int i = j; i >= 0; i--) {
                if (freq[s[i] - 'a']++ == 0) {
                    left_distinct++;
                }
                left[left_distinct]++;
            }
            int right_distinct = 0;
            freq.assign(26,0);
            // for(int f : freq){
            //     cout<<f<<" ";
            // }
            for (int k = j + 1; k < n; k++) {
                if (freq[s[k] - 'a']++ == 0) {
                    right_distinct++;
                }
                ans += left[right_distinct];
            }
        }
        return ans;
    }
};