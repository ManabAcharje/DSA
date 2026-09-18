class Solution {
public:

    // logic abs val of angle created by hour and minutes
    //minutes=60  min create 360 dege so 1 min = 6degree
    //hour= 30* hour + minutes*0.5
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};