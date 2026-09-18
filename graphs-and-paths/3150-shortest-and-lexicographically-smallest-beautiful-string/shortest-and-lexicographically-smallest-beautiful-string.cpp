class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int i = 0;
        int one_count = 0;

        int min_len = INT_MAX;
        string ans = "";

        for (int j = 0; j < n; j++) {

           
            if (s[j] == '1')
                one_count++;

            
            if (one_count == k) {

                //jdi count k hoiya ja taile unnecessary 0 leading zero remove

                while (i < j && s[i] == '0') {
                    i++;
                }

                int curr_len = j - i + 1;
                string curr = s.substr(i, curr_len);

                //curr jdi small hy  min ans re update kr + miin _len 
                if (curr_len < min_len) {
                    min_len = curr_len;
                    ans = curr;
                }

                // ar jdi curr == min hy taile ans re curr tar lge swap iff curr<ans
                else if (curr_len == min_len && curr < ans) {
                    ans = curr;
                }
            }

            // greater than k one
            
            if (one_count > k) {
                while (i <= j && one_count > k) {
                    if (s[i] == '1')
                        one_count--;
                    i++;
                }

                // Now we have exactly k ones.
                // Remove leading zeroes.
                while (i < j && s[i] == '0') {
                    i++;
                }

                int curr_len = j - i + 1;
                string curr = s.substr(i, curr_len);

                if (curr_len < min_len) {
                    min_len = curr_len;
                    ans = curr;
                }
                else if (curr_len == min_len && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};