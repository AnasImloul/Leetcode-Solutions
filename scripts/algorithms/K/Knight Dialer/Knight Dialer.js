// Runtime: 139 ms (Top 83.33%) | Memory: 48.9 MB (Top 52.38%)
var knightDialer = function(n) {

    let dp = Array(10).fill(1)
    let MOD = 10**9 + 7

    for(let i = 2; i <= n ; i++) {
        oldDp = [...dp]
        dp[0] = (oldDp[4] + oldDp[6]) % MOD
        dp[1] = (oldDp[8] + oldDp[6]) % MOD
        dp[2] = (oldDp[9] + oldDp[7]) % MOD
        dp[3] = (oldDp[8] + oldDp[4]) % MOD
        dp[4] = (oldDp[3] + oldDp[9] + oldDp[0]) % MOD
        dp[5] = 0
        dp[6] = (oldDp[0] + oldDp[7] + oldDp[1]) % MOD
        dp[7] = (oldDp[6] + oldDp[2]) % MOD
        dp[8] = (oldDp[3] + oldDp[1]) % MOD
        dp[9] = (oldDp[4] + oldDp[2]) % MOD
    }

    return dp.reduce((ans, ele) => ans += ele, 0) % MOD
};