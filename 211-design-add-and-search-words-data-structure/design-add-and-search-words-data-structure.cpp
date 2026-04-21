class WordDictionary {
public:
    unordered_map<int,vector<string>>mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[(int)word.size()].push_back(word);
    }
    
    bool search(string word) {
        
        for(auto &s:mp[(int)word.size()]){
            bool hasfound=true;
            for(int i=0;i<s.size();i++){
                if(word[i]!='.'){
                    if(s[i]!=word[i])
                    {
                        hasfound=false;
                        break;
                    }
                }
            }
            if(hasfound)return true;

        }
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */