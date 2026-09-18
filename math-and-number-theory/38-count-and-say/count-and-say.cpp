class Solution {
public:
    string rle(string s) {
        if (s == "1")
            return "11";
        int n = s.size();
        
        string result = "";
        int i = 0;

        while (i < n) {
            int count = 1;

            while (i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }

            result += to_string(count);
            result += s[i];
            i++;
        }
        return result;
    }
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return rle(countAndSay(n - 1));
    }
};