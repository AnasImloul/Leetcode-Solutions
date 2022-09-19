// Runtime: 2 ms (Top 12.57%) | Memory: 45.3 MB (Top 7.43%)
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int minRow=m,minCol=n;
        for(int[] op:ops){
            minRow=Math.min(minRow,op[0]);
            minCol=Math.min(minCol,op[1]);
        }
        return minRow*minCol;
    }
}