class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int bx = rec2[0];
        int by = rec2[1];
        int tx = rec2[2];
        int ty = rec2[3];

        if(bx>=x2 || by>=y2 || tx<=x1 || ty<=y1)return false;
        return true;
    }
};