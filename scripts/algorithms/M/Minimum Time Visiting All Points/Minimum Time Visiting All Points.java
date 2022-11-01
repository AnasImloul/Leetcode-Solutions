// Runtime: 2 ms (Top 57.50%) | Memory: 43.4 MB (Top 57.64%)
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int max = 0, x, y;
        for(int i = 0; i < points.length - 1; i++){
            for(int j = 0; j < points[i].length - 1; j++){
                x = Math.abs(points[i][j] - points[i+1][j]);
                y = Math.abs(points[i][j+1] - points[i+1][j+1]);
                max += Math.max(x,y);
            }
        }
        return max;
    }
}