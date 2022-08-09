class Solution {
    public double soupServings(int n) {
        //dp[i][j] = 0.25 * dp[i - 100][j] + 0.25 * dp[i - 75][j - 25]
        //         + 0.25 * dp[i - 50][j - 50] + 0.25 * dp[i - 75][j - 25]

        if (n >= 4276){
            return 1;
        }

        n = (n + 24) / 25;
        double[][] dp = new double[n + 1][n + 1];

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 && j == 0){
                    dp[i][j] = 0.5;
                }else if (i == 0){
                    dp[i][j] = 1;
                }else if (j == 0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] += dp[max(i - 4)][j] * 0.25;
                    dp[i][j] += dp[max(i - 3)][max(j - 1)] * 0.25;
                    dp[i][j] += dp[max(i - 2)][max(j - 2)] * 0.25;
                    dp[i][j] += dp[max(i - 1)][max(j - 3)] * 0.25;
                }
            }
        }

        return dp[n][n];
    }

    private int max(int a){
        return Math.max(a, 0);
    }
}

//class Solution {
//    public double soupServings(int n) {
//        //dp[i][j] = 0.25 * dp[i - 100][j] + 0.25 * dp[i - 75][j - 25]
//        //         + 0.25 * dp[i - 50][j - 50] + 0.25 * dp[i - 75][j - 25]

//        double[][] dp = new double[n + 1][n + 1];

//        for (int i = 0; i <= n; i++){
//            for (int j = 0; j <= n; j++){
//                if (i == 0 && j == 0){
//                    dp[i][j] = 0.5;
//                }else if (i == 0){
//                    dp[i][j] = 1;
//                }else if (j == 0){
//                    dp[i][j] = 0;
//                }else{
//                    dp[i][j] += dp[max(i - 100)][j] * 0.25;
//                    dp[i][j] += dp[max(i - 75)][max(j - 25)] * 0.25;
//                    dp[i][j] += dp[max(i - 50)][max(j - 50)] * 0.25;
//                    dp[i][j] += dp[max(i - 25)][max(j - 75)] * 0.25;
//                }
//            }
//        }

//        return dp[n][n];
//    }

//    private int max(int a){
//        return Math.max(a, 0);
//    }
//}
