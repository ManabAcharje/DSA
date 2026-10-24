class Solution {
public:
     
    int countDaysTogether(string aA, string aL, string bA, string bL) {

        int days = 0;
        if (aA > bA)
            return countDaysTogether(bA, bL, aA, aL);
        if (aL < bA)
            return 0;

     
        string startOverlap = bA;
        string endOverlap = min(aL, bL);
        stringstream a(startOverlap);
        int f = 0, l = 0;
        char c = '-';
        a >> f >> c >> l;
        stringstream b(endOverlap);
        int f2 = 0, l2 = 0;
        char c2 = '-';
        b >> f2 >> c2 >> l2;
        

        for(int m  = f ; m  < f2; m ++) {
            if ((m > 7 && !(m & 1)) || (m <= 7 && (m & 1)))
                days += 31;
            else if (m == 2) {
                days += 28;
            } else
                days += 30;
        }
        days -=( l-1);
        days += l2;
        return days;
    }
};