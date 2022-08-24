// Runtime: 538 ms (Top 16.66%) | Memory: 372.3 MB (Top 5.18%)
class Solution {
    static Boolean[][][] dp;
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        dp = new Boolean[101][101][201]; // [row][col][open-close]
        if(grid[0][0] == ')'){ // cannot start with ')'
            return false;
        }
        if(grid[m-1][n-1] == '('){ // cannot end with '('
            return false;
        }
        return solve(grid,0,0,m,n,0,0);
    }
    public static boolean solve(char[][] grid,int i,int j,int m,int n,int open,int close){
        if(grid[i][j] == '('){
            open++;
        }
        else{
            close++;
        }
        if(close > open){ // at any point if closeBracket count exceeds openBracket count then return false since this path can never lead to valid paranthesis string
            return false;
        }
        if(i == m-1 && j == n-1){ // on reaching bottom right cell if openCount == closeCount return true else return false
            return open == close;
        }
        if(dp[i][j][open-close] != null){ // check for precomputed overlapping subproblem
            return dp[i][j][open-close];
        }
        if(i == m-1){ // make sure to not go out of the grid in last row
            return dp[i][j][open-close] = solve(grid,i,j+1,m,n,open,close);
        }
        if(j == n-1){ // make sure to not go out of the grid in last col
            return dp[i][j][open-close] = solve(grid,i+1,j,m,n,open,close);
        }
        boolean op = solve(grid,i+1,j,m,n,open,close) || solve(grid,i,j+1,m,n,open,close); // we have two choices to move forward, [i+1][j] or [i][j+1]
        return dp[i][j][open-close] = op;
    }
}