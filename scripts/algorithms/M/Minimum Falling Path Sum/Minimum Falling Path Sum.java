// Runtime: 3 ms (Top 82.59%) | Memory: 46.9 MB (Top 82.02%)

class Solution {
    public int min(int[][] matrix, int[][]dp, int i, int j)
    {
        int a,b,c;
        if(i==0)
            return matrix[i][j];
        if(dp[i][j] != Integer.MAX_VALUE)
            return dp[i][j];
        if(j==0)
        {
            dp[i][j] = Math.min(min(matrix, dp, i-1,j),min(matrix, dp, i-1, j+1))+matrix[i][j];
        }
        else if(j==matrix.length -1)
        {
            dp[i][j] = Math.min(min(matrix, dp, i-1,j),min(matrix, dp, i-1, j-1))+matrix[i][j];
        }
        else
        {
            dp[i][j] = Math.min(Math.min(min(matrix, dp, i-1,j),min(matrix, dp, i-1, j+1)),min(matrix, dp, i-1, j-1))+matrix[i][j];
        }
        return dp[i][j];
    }

    public int minFallingPathSum(int[][] matrix) {
        int dp[][] = new int[matrix.length][matrix.length];
        if(matrix.length == 1)
            return matrix[0][0];
        for(int i=0;i<matrix.length;i++)
            for(int j=0;j<matrix.length;j++)
                dp[i][j] = Integer.MAX_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<matrix.length; i++)
        {
            min = Math.min(min, min(matrix, dp, matrix.length-1,i));
        }
        return min;
    }
}