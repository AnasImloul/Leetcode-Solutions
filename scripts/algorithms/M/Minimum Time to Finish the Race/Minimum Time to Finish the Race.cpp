// Runtime: 2419 ms (Top 5.20%) | Memory: 274.6 MB (Top 9.24%)
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        // to handle the cases where numLaps is small
        // without_change[i][j]: the total time to run j laps consecutively with tire i
        vector<vector<int>> without_change(n, vector<int>(20, 2e9));
        for (int i = 0; i < n; i++) {
            without_change[i][1] = tires[i][0];
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] * tires[i][1] >= 2e9)
                    break;
                without_change[i][j] = without_change[i][j-1] * tires[i][1];
            }
            // since we define it as the total time, rather than just the time for the j-th lap
            // we have to make it prefix sum
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] + without_change[i][j] >= 2e9)
                    break;
                without_change[i][j] += without_change[i][j-1];
            }
        }

        // dp[x]: the minimum time to finish x laps
        vector<int> dp(numLaps+1, 2e9);
        for (int i = 0; i < n; i++) {
            dp[1] = min(dp[1], tires[i][0]);
        }
        for (int x = 1; x <= numLaps; x++) {
            if (x < 20) {
                // x is small enough, so an optimal solution might never changes tires!
                for (int i = 0; i < n; i++) {
                    dp[x] = min(dp[x], without_change[i][x]);
                }
            }
            for (int j = x-1; j > 0 && j >= x-18; j--) {
                dp[x] = min(dp[x], dp[j] + changeTime + dp[x-j]);
            }
        }

        return dp[numLaps];
    }
};