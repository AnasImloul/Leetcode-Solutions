class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int res[] = new int[m*n];
        int diags = m+n-1;
        int mode = 0, x, y, pos = 0;
        for(int d = 0; d < diags; d++) {
            
            if(mode %2 == 0){
                x = Math.min(d,m-1);
                y = d-x;
            } else {
                y = Math.min(d,n-1);
                x = d-y;
            }
            while(x >= 0 && y >= 0 && x < m && y < n && (x+y) == d){
                
                res[pos] = mat[x][y];
                
                if(mode%2 == 0){
                    x--; y++;
                } else {
                    x++; y--;
                }
                pos++;
            }
            mode++;
        }
        
        return res;
    }
}
