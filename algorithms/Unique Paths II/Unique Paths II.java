class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[][] path = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
			//if there is an obstacle at the current block then you cannot get there
                if(obstacleGrid[i][j]!=1){
                    if(i==0 && j==0)
                        path[i][j] = 1;
                    if(i>0)
                        path[i][j] += path[i-1][j];
                    if(j>0)
                        path[i][j] += path[i][j-1];
                }
            }
        }
        return path[--m][--n];
    }
}
