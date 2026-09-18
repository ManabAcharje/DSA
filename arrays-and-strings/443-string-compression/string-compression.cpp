class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        if (n == 1) return 1;

        int groupLen = 1;
        int len = 0;

        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                groupLen++;
            } else {
                chars[len++] = chars[i - 1];

                if (groupLen > 1) {
                    string s = to_string(groupLen);

                    for (char c : s) {
                        chars[len++] = c;
                    }
                }

                groupLen = 1;
            }
        }

        // Process the last group
        chars[len++] = chars[n - 1];

        if (groupLen > 1) {
            string s = to_string(groupLen);

            for (char c : s) {
                chars[len++] = c;
            }
        }

        return len;
    }
};