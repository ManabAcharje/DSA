class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];

        if(sr==tr && tc==sc)return 0;
        if(sr == tr  || sc == tc || (sc+sr)==(tr+tc) ||(sc-sr == tc-tr))return 1;
        return 2;


    }
};