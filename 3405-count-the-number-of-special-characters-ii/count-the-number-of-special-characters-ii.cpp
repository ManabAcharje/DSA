class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>caps(26,0);
        vector<int>small(26,0);
        vector<int>canTake(26,true);

        for(auto &c:word){
            if(c>='a'){
                if(caps[c-'a']>=1)canTake[c-'a']=false;
                small[c-'a']++;
            }
            else if(c>='A'){
                caps[c-'A']++;

            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(canTake[i]){
                if(small[i]>0 && caps[i]>0)ans++;
            }
        }
        return ans;

    }
};