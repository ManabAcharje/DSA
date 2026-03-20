class Solution {
public:
    bool check(string& s, string& t) {
        int arr[26] = {0};

        for (int i = 0; i <s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        // also  need to know is string t valid or not 
        for (int i = 0; i <t.size(); i++) {
            if (arr[t[i] - 'a'] > 0)
                return true;
            arr[t[i]-'a']++;
            
            
        }
        return false;
    }
    int solve(vector<string>& arr, int i, int n, string s) {
        // base case
        if (i == n)
            return s.length();

        int pick = 0;
        int not_pick = 0;

        if (check(s, arr[i])) {// has duplicate
            not_pick = solve(arr, i + 1, n, s);
            pick = 0;
        } else {
            pick = solve(arr, i + 1, n, s + arr[i]);
            not_pick = solve(arr, i + 1, n, s);
        }

        return max(not_pick, pick);
    }
    int maxLength(vector<string>& arr) { 
        int n=arr.size();
        return solve(arr, 0, n, ""); 
    }
};