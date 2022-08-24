// Runtime: 1407 ms (Top 25.79%) | Memory: 92.6 MB (Top 35.19%)
class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        Integer[][] dp = new Integer[mat.length][5001];
        return minDiff(mat, 0, target,0, dp);
    }

    public int minDiff(int[][] mat,int index,int target, int val, Integer[][] dp){
        if(index == mat.length){
            return Math.abs(val - target);
        }
        if(dp[index][val] != null){
            return dp[index][val];
        }

        int res = Integer.MAX_VALUE;
        for(int i = 0; i < mat[0].length; i++){
            res = Math.min(res, minDiff(mat, index + 1, target, val + mat[index][i], dp));
        }

        return dp[index][val] = res;
    }
}