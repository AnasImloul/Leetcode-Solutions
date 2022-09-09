// Runtime: 39 ms (Top 41.82%) | Memory: 150.6 MB (Top 27.82%)
class Solution {
    int changeTime;
    public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
        this.changeTime = changeTime;
        int[] minTime = new int[numLaps + 1];
        Arrays.fill(minTime, Integer.MAX_VALUE);

        for (int[] tire : tires){
            populateMinTime(tire, minTime);
        }

        int[] dp = new int[numLaps + 1];
        for (int i = 1; i <= numLaps; i++){
            dp[i] = minTime[i]; // maxValue for dp[i] is Integer.MAX_VALUE, no need to worry about overflow
            for (int j = 1; j < i; j++){
                dp[i] = Math.min(dp[i], dp[j] + changeTime + dp[i - j]); // it will never overflow, since dp[j] are far less than Integer.MAX_VALUE
            }
        }
        return dp[numLaps];
    }

    private void populateMinTime(int[] tire, int[] minTime){
        int sum = 0;
        int base = tire[0];
        int ex = tire[1];
        int spent = 1;
        for (int i = 1; i < minTime.length; i++){
            spent = (i == 1) ? base : spent * ex;
            if (spent > changeTime + base){break;} // set boundary
            sum += spent;
            minTime[i] = Math.min(minTime[i], sum);
        }
    }
}