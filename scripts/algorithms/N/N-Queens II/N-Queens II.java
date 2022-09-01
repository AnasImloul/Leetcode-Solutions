// Runtime: 1 ms (Top 98.59%) | Memory: 41.2 MB (Top 48.22%)
class Solution {
    int count = 0;
    public int totalNQueens(int n) {
        boolean col[] = new boolean[n];
        boolean diag[] = new boolean[2*n-1];
        boolean rdiag[] = new boolean[2*n-1];

        countSolution(n,col, diag, rdiag, 0);
        return count;

    }
    void countSolution(int n, boolean[] col, boolean[] diag, boolean[] rdiag, int r ){
        if (r == n ){
            count++;
            return;
        }

        for(int c = 0 ; c < n; c++){
            if(col[c] == false && diag[r+c] == false && rdiag[r-c+n-1] == false){
                col[c] = true;
                diag[r+c] = true;
                rdiag[r-c+n-1] = true;
                countSolution(n, col, diag, rdiag, r+1);
                col[c] = false;
                diag[r+c] = false;
                rdiag[r-c+n-1] = false;
            }
        }

    }
}