class Solution {
public:
    string solve(string& s, int k) {
        
        if (s.size() <= k)
            return s;
        string ss = "";
        for (int i = 0; i < s.size(); i += k) {
            // cout<<"i  = " << i<<endl;
            int sum = 0;
            for (int j = i; j < min((int)s.size(), i + k); j++) {
                sum += (s[j] - '0');
            }
            // cout<<"Sum = " <<sum<<endl;
            ss += to_string(sum);
        }
        return solve(ss, k);
    }
    string digitSum(string s, int k) { 
        return solve(s, k); 
    }
};