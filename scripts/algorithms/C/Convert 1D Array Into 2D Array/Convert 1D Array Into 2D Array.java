class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if(m * n != original.length) {
            return new int[0][0];
        }
        int[][] answer = new int[m][n];
        int rCount = 0, cCount = 0, len = original.length;
        for(int i=0;i<len;i++){
            answer[rCount][cCount++] = original[i];
            if(cCount == n) {
                rCount++;
                cCount = 0;
            }
        }
        return answer;
    }
}
