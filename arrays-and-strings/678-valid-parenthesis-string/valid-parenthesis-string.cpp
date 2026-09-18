class Solution {
public:
    int n;

    // bool valid(string& s) {
    //     int balance = 0;

    //     for (char c : s) {
    //         if (c == '(') {
    //             balance++;
    //         }
    //         else if (c == ')') {
    //             balance--;
    //             if (balance < 0)
    //                 return false;
    //         }
    //     }

    //     return balance == 0;
    // }

    int dp[101][201];
    bool solve(string& s, int i, int balance) {
        if (i == n )
            return balance == 0;

        if(dp[i][balance+100]!=-1)return dp[i][balance];

        if(s[i] =='*')
        {
            bool opt1 = solve(s,i+1,balance+1);

            bool opt2 = false;
            s[i]  = ')';
            if(balance-1>=0) opt2 = solve(s,i+1,balance-1);
            s[i] = ' ';
            bool opt3 = solve(s,i+1,balance); 

            return dp[i][balance+100]=(opt1|| opt2|| opt3);
        }
        else{
            int opt1 = false;
            int opt2 = false;
            if(s[i]=='('){
                opt1 = solve(s,i+1,balance+1);
            }
            else {
                if(balance-1>=0)
                    opt2 = solve(s,i+1,balance-1);  
            }
            return dp[i][balance+100] = opt1 || opt2;
        }
        return dp[i][balance+100]=false;

    }
    bool checkValidString(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};