class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        string ans = "";
        if (k >= n) {
            return "0";
        }

        for (int i = 0; i < n; i++) {
            while (!ans.empty() && k > 0 && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || num[i] != '0') {
                ans.push_back(num[i]);
            }
        }
        for (int i = k; i > 0; i--) {
            if(!ans.empty())
                ans.pop_back();
            else return "0";
        }
        if (ans.empty())
            return "0";

        return ans;
    }
};