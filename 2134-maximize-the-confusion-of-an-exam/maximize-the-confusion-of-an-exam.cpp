class Solution {
public:
    int solve(string& answers, int k) {
        int n = answers.size();
        int i = 0;
        int count = 0;
        int max_len = 0;
        for (int j = 0; j < n; j++) {
            if (answers[j] == 'F') {
                count++;
            }
            if (count > k) {
                while (count != k) {
                    if (answers[i] == 'F')
                        count--;
                    i++;
                }
            }
            max_len = max(max_len, j - i+1);
        }
        return max_len;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans1 = solve(answerKey, k);
        for (auto &ch : answerKey) {
            if (ch == 'T')
                ch = 'F';
            else
                ch = 'T';
        }
        int ans2 = solve(answerKey, k);
        // for(auto ch : answerKey)cout<<ch<<" ";
        return max(ans1, ans2);
    }
};