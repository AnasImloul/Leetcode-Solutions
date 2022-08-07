class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        
//         adding 1 to the front and back
        int[] temp = new int[n + 2];  
        temp[0] = 1;
        for(int i = 1; i < temp.length - 1; i++){
            temp[i] = nums[i-1];
        }
        temp[temp.length - 1] = 1;
        nums = temp;
        
//         memoization
        int[][] dp = new int[n+1][n+1];
        for(int[] row : dp){
            Arrays.fill(row, -1);
        }
        
//         result
        return f(1, n, nums, dp);
    }
    
    int f(int i, int j, int[] a, int[][] dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int max = Integer.MIN_VALUE;
        for(int n = i; n <= j; n++){
            int coins = a[i-1] * a[n] * a[j+1] + f(i, n-1, a, dp) + f(n+1, j, a, dp);
            max = Math.max(max, coins);
        }
        return dp[i][j] = max;
    }
}

// Time Complexity: O(N * N * N) ~ O(N^3);
// Space Complexity: O(N^2) + O(N);