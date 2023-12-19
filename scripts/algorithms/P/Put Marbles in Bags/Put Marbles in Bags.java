// Runtime: 35 ms (Top 32.52%) | Memory: 59.90 MB (Top 24.76%)

class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        if (k == n) return 0;
        int[] W = new int[n-1];
        for (int i = 1; i < n; i++) W[i-1] = weights[i] + weights[i-1];
        Arrays.sort(W);

        return max(W, k-1) - min(W, k-1);
    }
    
    private long max(int[] W, int k) {
        int n = W.length;
        long res = 0;
        for (int i = n-1; i >= n-k; i--) res += W[i];
        return res;
    }

    private long min(int[] W, int k) {
        long res = 0;
        for (int i = 0; i < k; i++) res += W[i];
        return res;
    }
}
