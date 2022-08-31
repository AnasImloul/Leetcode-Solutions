// Runtime: 219 ms (Top 27.71%) | Memory: 52.3 MB (Top 43.37%)
var minInsertions = function(s) {
    const len = s.length;
    const dp = new Array(len).fill(0).map(() => {
        return new Array(len).fill(-1);
    });

    const compute = (i = 0, j = len - 1) => {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return compute(i + 1, j - 1);

        return dp[i][j] = Math.min(
            compute(i + 1, j),
            compute(i, j - 1)
        ) + 1;
    }
    return compute();
};