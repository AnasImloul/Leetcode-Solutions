// Runtime: 7 ms (Top 78.37%) | Memory: 45.40 MB (Top 34.13%)

class Solution {
    private int n;
    private int res = 0;
    
    public int numSubmat(int[][] mat) {
        this.n = mat[0].length;
        
        // dp[j] : the height (number of consecutive '1's) of column j 
        int[] dp = new int[n];
        for (int i = 0; i < mat.length; i++) {
            // calculating (updating) heights
            for (int j = 0; j < n; j++) {
                dp[j] = mat[i][j] == 1 ? dp[j] + 1 : 0;
            }
            enumerateRowByMinHeight(dp);
        }
        return res;
    }

    public void enumerateRowByMinHeight(int[] dp) {
        // monotonic stack storing indices : for index p < q in stack, dp[p] < dp[q]
        Deque<Integer> stack = new LinkedList<>();
        stack.offerLast(-1);

        for (int j = 0; j < n; j++) {
            while (stack.peekLast() != -1 && dp[stack.peekLast()] >= dp[j]) {
                int idx = stack.pollLast();
                res += dp[idx] * (idx - stack.peekLast()) * (j - idx);
            }
            stack.offerLast(j);
        }
        while (stack.peekLast() != -1) {
            int idx = stack.pollLast();
            res += dp[idx] * (idx - stack.peekLast()) * (n - idx);
        }
    }
}
