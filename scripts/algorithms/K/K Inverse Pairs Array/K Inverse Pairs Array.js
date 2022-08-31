// Runtime: 191 ms (Top 53.06%) | Memory: 77.6 MB (Top 21.02%)
var kInversePairs = function(n, k) {
    const dp = new Array(n+1).fill(0).map(el => new Array(k+1).fill(0))
    const MOD = Math.pow(10, 9) + 7

    for(let i = 0; i < n+1; i++) {
        dp[i][0] = 1
    }

    for(let i = 1; i <= n; i++) {
        for(let j = 1; j <= k; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j] % MOD) - (j >= i ? dp[i-1][j-i] : 0)%MOD
        }
    }

    return dp[n][k] % MOD
};