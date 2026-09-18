class Solution {
public:
    struct cmp {
        bool operator()(const string &a, const string &b) {
            if (a.size() == b.size())
                return a < b;

            return a.size() > b.size();
        }
    };

    string longestWord(vector<string>& words) {

        unordered_set<string> st(words.begin(), words.end());

        sort(words.begin(), words.end(), cmp());

        string ans = "";

        for (auto &word : words) {

            bool valid = true;

            for (int i = 1; i < word.size(); i++) {

                if (!st.count(word.substr(0, i))) {
                    valid = false;
                    break;
                }
            }

            if (valid){
                ans = word;
                break;
            }
        }

        return ans;
    }
};