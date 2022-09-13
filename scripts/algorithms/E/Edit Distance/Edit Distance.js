// Runtime: 135 ms (Top 56.56%) | Memory: 46.3 MB (Top 80.04%)
var minDistance = function(word1, word2) {
    const m = word1.length;
    const n = word2.length;

    const memo = new Array(m).fill().map(() => new Array(n));
    const dfs = (i = m - 1, j = n - 1) => {
        if(i < 0 && j < 0) return 0;
        if(i < 0 && j >= 0) return j + 1;
        if(i >= 0 && j < 0) return i + 1;
        if(memo[i][j] !== undefined) return memo[i][j];

        if(word1[i] === word2[j]) {
            return memo[i][j] = dfs(i - 1, j - 1);
        }

        return memo[i][j] = 1 + Math.min(...[
            dfs(i, j - 1),
            dfs(i - 1, j),
            dfs(i - 1, j - 1)
        ]);
    }

    return dfs();
};