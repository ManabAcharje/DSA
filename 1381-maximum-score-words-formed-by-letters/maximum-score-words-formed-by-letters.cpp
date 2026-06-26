// list  of words
// list of letters
// score of chars
// return max score of any valid set words form by using givent
// words[i] can not

// need char freq;// we have this but need to change in map-> to effienly ly
// use;

// need char score; --> we have this already

// dog +  cat + dad + good
//  what i can choose out of them
//  dog _ can  i build dog if  yes-> one opt is go with dog or skip dog

// and os on so it is a dp question;

// what words i can build using these letters
// and i need to return the max score
class Solution {
public:
    unordered_map<char, int> freq;
    int n;
    vector<int>scores;
    vector<string>words;

    bool canBuild(string &s ,unordered_map<char,int>&freq){
        unordered_map<char,int> temp = freq;
        for(auto &ch: s){
            if(temp[ch]==0)return false;
            temp[ch]--;
        }
        return true;
    }

    int solve(int i,unordered_map<char,int>&freq) {
        if (i == n)
            return 0;
        int opt1 = 0;
        if (canBuild(words[i],freq)) {
            int score = 0 ;
            for(auto  &c: words[i]){
                score+=scores[c-'a'];
                freq[c]--;
            }
            opt1 = score + solve(i+1,freq);
            for(auto  &c : words[i]){
                freq[c]++;
            }
        }
        int opt2 = solve(i+1,freq);

        return max(opt1,opt2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& scores) {

        n = words.size();
        this->scores= scores;
        this->words= words;
        for (auto& ch : letters) {
            freq[ch]++;
        }
        return solve(0,freq);
    }
};