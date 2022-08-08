class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int[][] ans = new int[rows*cols][2];
        int i=0;
        ans[i++] = new int[]{rStart, cStart};
        
        int len=0;
        int d=0;
        int[] direction = new int[]{0, 1, 0, -1, 0};
        
        while(i < rows * cols){
            if(d == 0 || d == 2){
                len++;
            }
            for(int k=0; k<len; k++){
                rStart += direction[d];
                cStart += direction[d+1];
                
                if(rStart<rows && rStart>=0 && cStart<cols && cStart >= 0){
                    ans[i++] = new int[]{rStart, cStart};
                }
            }
            d = ++d % 4;
        }
        return ans;
    }
}
