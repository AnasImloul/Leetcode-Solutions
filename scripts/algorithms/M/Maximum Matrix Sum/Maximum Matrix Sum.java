class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long ans = 0;
        int neg = 0;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] < 0) {
                    neg++;
                }
                ans += Math.abs(matrix[i][j]);
                if(min > Math.abs(matrix[i][j]))
                	min = Math.abs(matrix[i][j]);
            }
        }
        if(neg % 2 == 0)
        	return ans;
        else
        	return ans - 2*min;
    }
}
