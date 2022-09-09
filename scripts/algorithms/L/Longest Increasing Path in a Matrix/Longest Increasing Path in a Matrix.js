// Runtime: 196 ms (Top 48.11%) | Memory: 50.6 MB (Top 47.62%)
var longestIncreasingPath = function(matrix) {
    const m = matrix.length, n = matrix[0].length;
    const dp = new Array(m).fill(0).map(() => {
        return new Array(n).fill(-1);
    });

    let ans = 0;
    const dir = [0, -1, 0, 1, 0];

    const dfs = (x, y) => {
        if(dp[x][y] != -1) return dp[x][y];

        for(let i = 1; i <= 4; i++) {
            const [nx, ny] = [x + dir[i], y + dir[i - 1]];
            if(
                nx >= 0 && ny >= 0 &&
                nx < m && ny < n &&
                matrix[nx][ny] > matrix[x][y]
            ) {
                dp[x][y] = Math.max(dp[x][y], 1 + dfs(nx, ny));
            }
        }

        if(dp[x][y] == -1) dp[x][y] = 1;
        ans = Math.max(ans, dp[x][y]);
        return dp[x][y];
    }

    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            if(dp[i][j] == -1) dfs(i, j);
        }
    }

    return ans;
};