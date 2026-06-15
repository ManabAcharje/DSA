class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCnt;// each frequency how many times

            for (int j = i; j < n; j++) {
                int x = nums[j];

                int oldFreq = freq[x];

                if (oldFreq > 0) {
                    freqCnt[oldFreq]--;

                    if (freqCnt[oldFreq] == 0) {
                        freqCnt.erase(oldFreq);
                    }
                }

                freq[x]++;

                int newFreq = freq[x];
                freqCnt[newFreq]++;

                bool valid = false;

                if (freq.size() == 1) {
                    valid = true;
                }
                else if (freqCnt.size() == 2) {
                    auto it = freqCnt.begin();

                    int a = it->first;
                    ++it;
                    int b = it->first;

                    int f = min(a, b);
                    int g = max(a, b);

                    valid = (g == 2 * f);
                }

                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};