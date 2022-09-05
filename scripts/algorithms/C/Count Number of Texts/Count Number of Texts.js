// Runtime: 134 ms (Top 52.17%) | Memory: 48.8 MB (Top 91.30%)
var countTexts = function(pressedKeys) {
    const MOD = 1e9 + 7;
    const n = pressedKeys.length;
    const dp = new Array(n + 1).fill(0);

    dp[0] = 1;

    let lastChar = "";
    let repeatCount = 0;

    for (let i = 1; i <= n; ++i) {
        const currChar = pressedKeys[i - 1];

        if (currChar != lastChar) repeatCount = 0;

        lastChar = currChar;
        repeatCount += 1;

        dp[i] = (dp[i] + dp[i - 1]) % MOD;

        if (i >= 2 && repeatCount >= 2) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        if (i >= 3 && repeatCount >= 3) dp[i] = (dp[i] + dp[i - 3]) % MOD;
        if ((currChar == "7" || currChar == "9") && i >= 4 && repeatCount >= 4) dp[i] = (dp[i] + dp[i - 4]) % MOD;
     }

    return dp[n];
};