class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length; 
        int m = mat[0].length;
        for(int i=0;i<m;i++){
            give(0,i,mat,n,m);
        }
        for(int i=1;i<n;i++){
            give(i,0,mat,n,m);
        }
        return mat;
    }
    public void give(int i,int j,int[][] mat,int n,int m){
        int[] dig = new int[Math.min(m-j,n-i)];
        int r = i;
        int c = j;
        int k = 0;
        while(r<n && c<m){
            dig[k] = mat[r][c];
            r++;
            c++;
            k++;
        }
        Arrays.sort(dig);
        k = 0;
        while(i<n && j<m){
            mat[i][j] = dig[k];
            i++;
            j++;
            k++;
        }
    }
}