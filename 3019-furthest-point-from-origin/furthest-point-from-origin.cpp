class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int _=0;
        int right=0;
        for(auto move:moves){
            if(move=='L')left++;
            else if(move=='R')right++;
            else _++;

        }
        return abs(right-left)+_;
    }
};