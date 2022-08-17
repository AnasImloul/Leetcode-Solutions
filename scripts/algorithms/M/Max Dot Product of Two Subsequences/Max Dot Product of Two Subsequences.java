class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] dp = new int[n+1][m+1];
        for(int[] d : dp) // can skip this step in case of tabulation
            Arrays.fill(d, -(int)1e9);
        // return maxDotProduct_Memo(nums1, nums2, n, m, dp);
        return maxDotProduct_Tab(nums1, nums2, n, m, dp);
    }
    
    public int maxDotProduct_Tab(int[] nums1, int[] nums2, int N, int M, int[][] dp){
        for(int n = 0; n <= N; n++){
            for(int m = 0; m <= M; m++){
                if(n == 0 || m == 0){
                    dp[n][m] = -(int)1e8;
                    continue;
                }
                int val = nums1[n-1] * nums2[m-1];
                int acceptedBothNumbers = dp[n-1][m-1] + val;
                int a = dp[n-1][m];
                int b = dp[n][m-1];

                dp[n][m] = getMax(val, acceptedBothNumbers, a, b); // max of above 4 conditions
            }
        }
        return dp[N][M];
    }

    public int maxDotProduct_Memo(int[] nums1, int[] nums2, int n, int m, int[][] dp) {
        if(n == 0 || m == 0)
            return dp[n][m] = -(int)1e8; // to differentiate it from initial dp value we put -1e8 instead of -1e9
        
        if(dp[n][m] != -(int)1e9) return dp[n][m];

        int val = nums1[n-1] * nums2[m-1]; // all the numbers will give -ve ans instead of these two indices eg. [20,-3,-4,-5] && [3,2,1]
        int acceptedBothNumbers = maxDotProduct_Memo(nums1, nums2, n-1, m-1, dp) + val; // we may expect a positive number from other numbers too and also we got +ve ans from first indices of both the arr
        int a = maxDotProduct_Memo(nums1, nums2, n-1, m, dp); // 1st idx from nums1 is giving -ve ans so we drop it
        int b = maxDotProduct_Memo(nums1, nums2, n, m-1, dp); // 1st idx from nums2 is giving -ve ans so we drop it

        return dp[n][m] = getMax(val, acceptedBothNumbers, a, b); // max of above 4 conditions
    }

    public int getMax(int... arr){
        int max = arr[0];
        for(int ele : arr) max = Math.max(ele, max);
        return max;
    }
}
