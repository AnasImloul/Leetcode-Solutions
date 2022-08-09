// Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/

class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int sum = 0;
        for (int i = 0; i < timeSeries.length; i++) {
            if (i == 0) {
                sum += duration;
            } else {
                sum += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
            }
        }
        return sum;       
    }
}
