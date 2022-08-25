// Runtime: 3 ms (Top 36.61%) | Memory: 5.9 MB (Top 34.68%)
class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle = 30*(double(hour) + double(minutes/60.0));

        double minuteAngle = 6 * (double)minutes;

        return 180 - abs(180 - abs(minuteAngle - hourAngle));

    }
};