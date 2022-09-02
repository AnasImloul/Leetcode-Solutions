// Runtime: 414 ms (Top 33.56%) | Memory: 88.6 MB (Top 56.51%)
var longestPalindromeSubseq = function(s) {
    const { length } = s;
    const dp = Array(length).fill('').map(() => Array(length).fill(0));

    for (let start = 0; start < length; start++) {
        const str = s[start];
        dp[start][start] = 1;

        for (let end = start - 1; end >= 0; end--) {
            dp[start][end] = str === s[end]
                ? dp[start - 1][end + 1] + 2
                : Math.max(dp[start - 1][end], dp[start][end + 1])
        }
    }
    return dp[length - 1][0];
};