class Solution {
public:

    bool oneCharDiff(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;
            if(diff>1)return false;
        }

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        bool exists = false;
        for (auto &word : wordList) {
            if (word == endWord) {
                exists = true;
                break;
            }
        }

        if (!exists)
            return 0;

        unordered_map<string, vector<string>> mp;

        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (oneCharDiff(wordList[i], wordList[j])) {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (oneCharDiff(beginWord, wordList[i])) {
                mp[beginWord].push_back(wordList[i]);
                mp[wordList[i]].push_back(beginWord);
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int len = 1;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                string u = q.front();
                q.pop();

                if (u == endWord)
                    return len;

                for (auto &v : mp[u]) {

                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            len++;
        }

        return 0;
    }
};