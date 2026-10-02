class Solution {
public:
    vector<string>ans;
    int n;
    void solve(int lc,int rc , string &s){
        cout<<lc<<" "<<rc<<" "<<s<<"\n";
        
        if(lc==rc && lc == n ){
            cout<<"pushed "<<s<<" "<<"\n";
            ans.push_back(s);
            return;
        }
        if(lc<n){
        s+="(";
        solve(lc + 1 , rc, s);
        s.pop_back();
        }
        if(lc>rc){
            s+=")";
            solve(lc,rc+1,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string s = "";
        solve(0,0,s);
        return ans;
    }
};