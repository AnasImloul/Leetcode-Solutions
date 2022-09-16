// Runtime: 88 ms (Top 26.15%) | Memory: 43.2 MB (Top 92.07%)
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length,n = mat[0].length;
        int[][] answer = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = 0;
                // take new variables to get starting index of mat[r][c]
                int p = i-k,q=j-k;
                //make sure p and q are atleast 0 (i.e. valid)
                while(p<0)
                    p++;
                while(q<0)
                    q++;
                //traverse again in the matrix with starting at p,q and ending at i+k and j+k
                //add conditions to make sure the indices dont cross the values of m and n
                for(int x = p;x<=i+k && x<m;x++){
                    for(int y = q;y<=j+k && y<n;y++){
                        val += mat[x][y];
                    }
                }
                answer[i][j] = val;
            }
        }
        return answer;
    }
}