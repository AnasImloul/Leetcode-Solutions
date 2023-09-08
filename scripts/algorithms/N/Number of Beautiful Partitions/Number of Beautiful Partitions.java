// Runtime: 21 ms (Top 82.3%) | Memory: 56.41 MB (Top 50.9%)

class Solution {
    int mod = 1000000007;
    boolean is[];
    public int beautifulPartitions(String s, int K, int minLength) {
        is = new boolean[10];
        is[2] = is[3] = is[5] = is[7] = true;
        
        int n = s.length();
        int a[] = new int[n + 1];
        for(int i = 0; i < n; i++) a[i + 1] = s.charAt(i) - '0';
        if(!is[a[1]]) {
            return 0;
        }
        
        long dp[][] = new long[n + 1][K + 1];
        long m[] = new long[K + 1];        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            if(i >= minLength) {
                int idx = i - minLength;
                if(idx == 0 || (!is[a[idx]] && (idx + 1 > n || is[a[idx + 1]]))) { // keep maximum
                    for(int k = 0; k <= K; k++) {
                        m[k] += dp[idx][k];
                        m[k] %= mod;
                    }
                }
            }
            if(is[a[i]]) continue;
            for(int k = 1; k <= K; k++) {
                dp[i][k] += m[k - 1];
                dp[i][k] %= mod;
            }
        }
        return (int)(dp[n][K]);
    }
}