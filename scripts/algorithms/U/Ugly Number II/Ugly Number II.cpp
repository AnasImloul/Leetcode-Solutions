// Runtime: 4 ms (Top 94.55%) | Memory: 6 MB (Top 90.93%)
class Solution {
public:
    int nthUglyNumber(int n) {

        int dp[n+1];
        dp[1] = 1;

        int p2 = 1, p3 = 1, p5 = 1;
        int t;

        for(int i = 2; i < n+1; i++){
            t = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            dp[i] = t;

            if(dp[i] == dp[p2]*2){
                p2++;
            }
            if(dp[i] == dp[p3]*3){
                p3++;
            }
            if(dp[i] == dp[p5]*5){
                p5++;
            }
        }
        return dp[n];

    }
};