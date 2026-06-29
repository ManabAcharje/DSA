class Solution {
public:
    bool sub(string &s ,string &w){
        if(s.size()>w.size())return false;
        for(int i = 0 ; i<=w.size()-s.size(); i++){
            if(w.substr(i,s.size())==s)return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;

        for(auto each : patterns){
            if(sub(each,word))count++;
        }
        return count;
    }
};