// Runtime: 1 ms (Top 58.12%) | Memory: 42.3 MB (Top 12.94%)
class Solution {
    public boolean isBoomerang(int[][] points) {
        double a, b, c, d, area;
        a=points[0][0]-points[1][0];
        b=points[1][0]-points[2][0];
        c=points[0][1]-points[1][1];
        d=points[1][1]-points[2][1];
        area=0.5*((a*d)-(b*c));
        return area!=0;
    }
}