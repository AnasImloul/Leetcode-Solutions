// Runtime: 87 ms (Top 83.78%) | Memory: 42.4 MB (Top 89.19%)
var minScoreTriangulation = function(values) {
    let dp = Array(values.length).fill().map((i) => Array(values.length).fill(0));
    function dfs(i, j) {
        if (dp[i][j]) return dp[i][j];
        if (j - i < 2) return 0;
        let min = Infinity;
        // k forms a triangle with i and j, thus bisecting the array into two parts
        // These two parts become two subproblems that can be solved recursively
        for (let k = i + 1; k < j; k++) {
            let sum = values[i] * values[j] * values[k] + dfs(i, k) + dfs(k, j);
            min = Math.min(min, sum);
        }
        return dp[i][j] = min;
    }
    return dfs(0, values.length - 1);
};