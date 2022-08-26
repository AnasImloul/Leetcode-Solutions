// Runtime: 0 ms (Top 100.00%) | Memory: 41.2 MB (Top 38.02%)
class Solution {
    public double angleClock(int hour, int minutes) {
        // Position of hour hand in a circle of 0 - 59
        double hrPos = 5 * (hour % 12);

        // Adjust hour hand position according to minute hand
        hrPos += (5 * minutes/60.0);

        double units = Math.abs(minutes - hrPos);

        // Take the min of distance between minute & hour hand and hour & minute hand
        return Math.min(units, 60-units) * 6;
    }
}