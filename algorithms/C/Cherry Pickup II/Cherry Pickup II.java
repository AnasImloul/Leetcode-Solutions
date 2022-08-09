Thank You : https://www.youtube.com/watch?v=ZV0sUzfA7Eg&ab_channel=Pepcoding

// Two person can satrt from (0,0) and reach (n-1, n-1) 
// First Person r1, c1
// Second Person r2, c2
// Both person will required equal steps to reach from (0,0) to (n-1, n-1) 

// r1 + c1 = r2 + c2;

class Solution {
    
    public int cherryPickup(int[][] grid) {
        int[][][] dp = new int[grid.length][grid.length][grid.length];
        return Math.max(0, cp(0, 0, 0, grid.length, grid, dp));
    }
    
    public  int cp(int r1, int c1, int r2, int n, int[][] arr, int[][][] dp) {
        int c2 = r1+ c1 - r2;    // r1 + c1 = r2 + c2
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || arr[r1][c1] == -1 || arr[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
      
	   // When We reach on destionation. If P1 reached means P2 also reaches at the same time
        if(r1 == n - 1 && c1 == n - 1) {
            return arr[r1][c1];
        }
      
        int cherries = 0;
        
        if(dp[r1][c1][r2] != 0) {
            return dp[r1][c1][r2];
        }

        if(r1 == r2 && c1 == c2) {
            cherries = arr[r1][c1];  //If both persons come on same position then we need to allow only one person can pick up cherries
        } else {  // otherwise both person can pick up 
            cherries = arr[r1][c1] + arr[r2][c2];
        }

        int f1 = cp(r1, c1+1, r2, n, arr, dp);
        int f2 = cp(r1 + 1, c1, r2, n, arr, dp);
        int f3 = cp(r1 + 1, c1, r2+1, n, arr, dp);
        int f4 = cp(r1, c1+1, r2+1, n, arr, dp);

		// Find the maximum value
        cherries +=  Math.max(Math.max(f1, f2) , Math.max(f3, f4));

        dp[r1][c1][r2] = cherries;
        return cherries;
    }
}
