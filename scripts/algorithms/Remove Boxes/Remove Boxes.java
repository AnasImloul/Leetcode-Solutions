class Solution {
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        int[][][] dp = new int[n][n][n];
        for (int i = n-1; i >= 0; i--){
            for (int j = i; j < n; j++){
                for (int k = 0; k < n; k++){
                    for (int m = i; m <= j; m++){
                        if (boxes[m] == boxes[i]){
                            dp[i][j][k]=Math.max(dp[i][j][k], (m-1<i+1?0:dp[i+1][m-1][0])+(k<n-1?dp[m][j][k+1]:0));
                        }
                    }
                    dp[i][j][k]=Math.max(dp[i][j][k], (i==n-1?0:dp[i+1][j][0])+(k+1)*(k+1));
                }
            }
        }
        return dp[0][n-1][0];
    }
}
