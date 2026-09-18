class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        vector<string>ans;
        for(auto &query:queries){
            for(auto &word: dictionary){


                int diff=0;
                for(int i=0;i<query.size();i++){
                    if(query[i]!=word[i]){
                        diff++;
                        if(diff>2){
                            break;
                        }
                    }

                }
                if(diff<=2){
                    ans.push_back(query);
                    break;
                }
            }

        }
        return ans;
    }
};