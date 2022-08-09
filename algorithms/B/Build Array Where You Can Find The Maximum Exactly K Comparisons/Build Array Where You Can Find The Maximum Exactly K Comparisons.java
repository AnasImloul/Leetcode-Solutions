class Solution {
    public int numOfArrays(int n, int m, int k) {
        int M = (int)1e9+7, ans = 0;
        int[][] dp = new int[m+1][k+1]; // maximum value, num of elements seen from left side
        for (int i = 1; i <= m; i++){
            dp[i][1]=1; // base case 
        }
        for (int i = 2; i <= n; i++){
            int[][] next = new int[m+1][k+1];
            for (int j = 1; j <= m; j++){ // for the current max value
                for (int p = 1; p <= m; p++){ // previous max value
                    for (int w = 1; w <= k; w++){ // for all possible k
                        if (j>p){ // if current max is larger, update next[j][w] from dp[p][w-1]
                            next[j][w]+=dp[p][w-1];
                            next[j][w]%=M;
                        }else{ // otherwise, update next[p][w] from dp[p][w]
                            next[p][w]+=dp[p][w];
                            next[p][w]%=M;
                        }
                    }
                }
            }
            dp=next;
        }
        for (int i = 1; i <= m; i++){ // loop through max that has k and sum them up.
            ans += dp[i][k];
            ans %= M;
        }
        return ans;
    }
}
