// Runtime: 101 ms (Top 86.16%) | Memory: 49.2 MB (Top 38.36%)
var knightProbability = function(n, k, row, column) {
    if (k === 0) return 1;
    const dirs = [[-2, -1], [-1, -2], [1, -2], [2, -1], [2, 1], [1, 2], [-1, 2], [-2, 1]];
    const dp = Array(k + 1)
        .fill('')
        .map(_ => Array(n).fill('').map(_ => Array(n).fill(0)));

    const isOut = (pos) => pos < 0 || pos > n - 1;
    const move = (x = row, y = column, step = k) => {
        if (step === 0) return 1;
        const moves = dp[step][x][y];
        if (moves !== 0) return moves;

        for (const [mvoeX, moveY] of dirs) {
            const nextX = x + mvoeX;
            const nextY = y + moveY;
            if (isOut(nextX) || isOut(nextY)) continue;

            dp[step][x][y] += move(nextX, nextY, step - 1);
        }
        return dp[step][x][y];
    };

    move();
    return dp[k][row][column] / 8 ** k;
};