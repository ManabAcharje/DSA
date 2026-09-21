class Solution {
public:
    int n;
    vector<string> ans;
    bool isValid(string t)
    {
        if(t.empty()|| t.size()>3)return false;
        if(t.size()>1 && t[0]=='0')return false;
        int val = stoi(t);
        return val>=0 && val<=255;
    }
    void solve(int i, int nod, string temp, string& s) 
    {
        if(nod == 3 ){
            if(i<n){
                string lastPart = s.substr(i);
                if(isValid(lastPart)){
                    ans.push_back(temp+lastPart);
                }
            }
            return ;
        }
        for(int len = 1; len <=3  && i+len<=n;len++){
            string part = s.substr(i,len);
            if(isValid(part)){
                solve(i+len,nod+1,temp+part+".",s);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        n  = s.size();
        string temp = "";
        solve(0,0,temp,s);
        return ans;
    }
};