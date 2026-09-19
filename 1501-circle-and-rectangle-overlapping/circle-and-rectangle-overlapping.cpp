class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        // min disance between two cener of circle and square 

        // if  the distane is <= r then true else false:
        // how to find the minimum distance
        // lets say x,y 
        // (x-xc)^2 + (y-yc)^  should be min
        // the min distance will min( horizontal distance , vertical distance , endPoint distace)
          //circle inside rec
        if(xc<=x2 && xc>=x1 && yc>=y1 && yc<=y2)return true;
        int x = clamp(xc,x1,x2)-xc;
        int y = clamp(yc , y1,y2)-yc;
        return x*x + y*y <= r*r;
        
    }
};