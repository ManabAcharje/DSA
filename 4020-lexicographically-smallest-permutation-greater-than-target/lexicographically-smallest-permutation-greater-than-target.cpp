class Solution {
public:
    // what solve will be  returning-> is it possible to get a result starting from idx
    bool solve(int idx, string &ans, vector<int> & freq, string &target)
    {
        int n = target.size();
        

        if(idx==n)return false;
        int x = target[idx]-'a';
        if(freq[x]>0)
        {
            freq[x]--;
            ans.push_back(target[idx]);
            if(solve(idx+1,ans,freq,target)){
                return true;
            }
            ans.pop_back();
            freq[x]++;
        }

        for(int c = x+1; c<26 ; c++)
        {
            if(freq[c]>0)
            {
                ans.push_back(c+'a');
                freq[c]--;
            
                for(int j = 0 ;j<26 ;j++){
                    while(freq[j]>0)    
                    {
                    ans.push_back('a'+j);
                    freq[j]--;
                    }
                }
                return true;
            }
        }
        return false;

    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        string ans = "";
        if(solve(0,ans,freq,target))return ans;
        return "";
    }
};