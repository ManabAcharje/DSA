class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            ans = (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1];
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            // A chain cannot start from a value that appears only once.
            if (cnt < 2) continue;

            long long curr = x;
            int len = 2;  // starting value contributes two copies

            while (true) {
                // Prevent overflow
                if (curr > 1000000000LL) break;

                long long next = curr * curr;

                if (!freq.count(next))
                    break;

                if (freq[next] >= 2) {
                    len += 2;
                    curr = next;
                } else {
                    len += 1;   // next becomes the peak
                    break;
                }
            }

            // If we stopped because next doesn't exist,
            // current becomes the peak instead of contributing two copies.
            if (!freq.count(curr * curr))
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};