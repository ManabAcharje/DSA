class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //return arr paris of lenght n wher pairs[i] state ->no of postion will form succ ithspell , product of 5*()>=sucess

        // one thing to notice is no of potion min  potions strength required to be success full
        //sort the potions and use binary search

        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int> pairs(n,0);
        for(int i=0; i<n;i++){
            long long  target=(success+spells[i]-1)/spells[i];
            auto it = lower_bound(potions.begin(),potions.end(),target);
            int idx= it-potions.begin();
            pairs[i]=m-idx;
        }
        return pairs;
    }
};