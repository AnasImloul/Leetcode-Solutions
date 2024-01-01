// Runtime: 63 ms (Top 71.43%) | Memory: 43.50 MB (Top 100.0%)

/**
 * @param {number} n
 * @param {number} goal
 * @param {number} k
 * @return {number}
 */
var numMusicPlaylists = function(n, goal, k) {
    const MOD = 1e9 + 7;
    let dp = Array.from({length: 2}, () => new Array(n + 1).fill(0));
    dp[0][0] = 1;

    for (let i = 1; i <= goal; i++) {
        dp[i%2][0] = 0;
        for (let j = 1; j <= Math.min(i, n); j++) {
            dp[i%2][j] = dp[(i - 1)%2][j - 1] * (n - (j - 1)) % MOD;
            if (j > k)
                dp[i%2][j] = (dp[i%2][j] + dp[(i - 1)%2][j] * (j - k)) % MOD;
        }
    }

    return dp[goal%2][n];
};
