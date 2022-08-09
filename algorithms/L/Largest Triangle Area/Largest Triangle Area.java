class Solution {
    public double largestTriangleArea(int[][] points) {
        double ans = 0;
        int n = points.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans = Math.max(ans,0.5*Math.abs(points[i][0]*(points[j][1] - points[k][1]) + points[j][0]*( points[k][1] - points[i][1]) + points[k][0]*(points[i][1] - points[j][1])));
                }
            }
        }
        return ans;
    }
}