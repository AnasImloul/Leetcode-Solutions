class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int rows = mat.length;
        int cols = mat[0].length;
        int[][] preSum = new int[rows+1][cols+1];
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int lo=1,hi=Math.min(rows,cols);
        while(lo<=hi){
            int m = (lo+hi)>>1;
            if(fun(preSum,threshold,rows,cols,m)) lo=m+1;
            else hi=m-1;
        }
        return lo-1;
    }
    private boolean fun(int[][] preSum, int maxSum,int rows, int cols, int size){
        for(int r=size;r<=rows;r++){
            for(int c=size;c<=cols;c++){
                int sum = preSum[r][c] - preSum[r-size][c] - preSum[r][c-size] + preSum[r-size][c-size];
                if(sum <= maxSum) return true;
            }
        }
        return false;
    }
}
