// Runtime: 2912 ms (Top 12.50%) | Memory: 51.4 MB (Top 50.00%)
var stoneGameV = function(stoneValue) {
    // Find the stoneValue array's prefix sum
    let prefix = Array(stoneValue.length).fill(0);
    for (let i = 0; i < stoneValue.length; i++) {
        prefix[i] = stoneValue[i] + (prefix[i - 1] || 0);
    }

    let dp = Array(stoneValue.length).fill().map(() => Array(stoneValue.length).fill(0));

    function game(start, end) {
        if (dp[start][end]) return dp[start][end];
        if (start === end) return 0;

        let max = 0;
        for (let i = start + 1; i <= end; i++) {
            let sumL = prefix[i - 1] - (prefix[start - 1] || 0);
            let sumR = prefix[end] - (prefix[i - 1] || 0);
            if (sumL > sumR) {
                max = Math.max(max, sumR + game(i, end));
            } else if (sumL < sumR) {
                max = Math.max(max, sumL + game(start, i - 1));
            } else {
                // If tied, check both rows
                let left = sumR + game(i, end);
                let right = sumL + game(start, i - 1);
                max = Math.max(max, left, right);
            }
        } return dp[start][end] = max;
    }

    return game(0, stoneValue.length - 1);
};