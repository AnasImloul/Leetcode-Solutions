// Runtime: 0 ms (Top 100.0%) | Memory: 39.60 MB (Top 43.22%)

class Solution {
    int ans;
    
    public int totalNQueens(int N) {
        ans = 0;
        place(0,0,0,0,N);
        return ans;
    }
    
    private void place(int i, int vert, int ldiag, int rdiag, int N) {
        if (i == N) ans++;
        else for (int j = 0; j < N; j++) {
            int vmask = 1 << j, lmask = 1 << (i+j), rmask = 1 << (N-i-1+j);
            if ((vert & vmask) + (ldiag & lmask) + (rdiag & rmask) > 0) continue;
            place(i+1, vert | vmask, ldiag | lmask, rdiag | rmask, N);
        }
    }
}
