// Runtime: 76 ms (Top 76.19%) | Memory: 47.60 MB (Top 52.38%)

/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(piles) {
    let sum = 0;
    const dp = new Array(101).fill(0).map(() => new Array(201).fill(0));
    for(let i = 0; i < piles.length; i++) {
        sum += piles[i];
    }
    let diff = help(0, 1, piles, dp);
    return (sum + diff) / 2;
};

function help(i, M, piles, dp) {
    if(i >= piles.length)
        return 0;
    if(dp[i][M] != 0)
        return dp[i][M];
    let total = 0;
    let ans = Number.MIN_SAFE_INTEGER;
    for(let j = 0; j < 2 * M; j++) {
        if(i + j < piles.length)
            total += piles[i+j];
        ans = Math.max(ans, total - help(i+j+1,Math.max(M,j+1),piles, dp));
    }
    dp[i][M] = ans;
    return ans;
}
