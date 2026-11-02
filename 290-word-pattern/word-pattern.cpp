class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //     unordered_map<string, int> str_freq;
        //     unordered_map<char, int > char_freq;

        //     int char_count = 0;

        //     for (int i = 0; i < pattern.size(); i++) {
        //         char_freq[pattern[i]]++;
        //         char_count++;

        //     }
        //     // cout<<char_seen.size();

        //     string str = "";
        //     int str_count = 0;
        //     int n = s.size();
        //     for (int i = 0; i < n; i++) {
        //         if (s[i] == ' ') {
        //             if (!str.empty()) {
        //                 str_freq[str]++;
        //                 str_count++;

        //             }
        //             str = "";
        //         } else {
        //             str += s[i];
        //         }
        //     }
        //     if (!str.empty()) {
        //         str_freq[str]++;
        //         str_count++;
        //     }
        //     cout<<char_count<<endl;
        //     cout<<str_count<<endl;
        //     if(char_count!=str_count)return false;

        //     //now i need to check from both the map

        //     unordered_map<int,int>mp;
        //     for(auto it: char_freq){
        //         mp[it.second]++;
        //     }
        //     for(auto it: str_freq){
        //        int x =  mp[it.second]--;
        //     //    if(x < 0)return false;

        //     }
        //     for(auto it : mp){
        //         if(it.second != 0)return false;
        //     }
        //     return true;

        // }

        unordered_map<char, string> mp;
        vector<string> strs;
        string str = "";


        int n = s.size();
        for (int i = 0; i < n; i++) 
        {
            if (s[i] == ' ') {
                if (!str.empty())
                {
                    strs.push_back(str);
                    
                }
                str = "";
            } else {

                str += s[i];
            }
        }
        if (!str.empty()) {
            strs.push_back(str);
        }
        for(auto str : strs){
            cout<<str<<" ";
        }

        if(strs.size() != pattern.size())return false;
        unordered_set<string>already_mapped;

        for (int i = 0; i < pattern.size();i++) {

            if(mp.contains(pattern[i])){
                if(mp[pattern[i]] != strs[i]){
                    return false;
                }
               
            }else{
                if(already_mapped.count(strs[i]))return false;
                mp[pattern[i]] = strs[i];
                already_mapped.insert(strs[i]);
            }
        }
        return true;
    }
};
    /*
        a->2
        b->2


        cat->3
        dog->1
    */
