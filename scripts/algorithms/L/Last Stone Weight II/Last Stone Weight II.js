// Runtime: 133 ms (Top 21.62%) | Memory: 42.3 MB (Top 86.49%)
var lastStoneWeightII = function(stones) {
    var sum = stones.reduce((a, b) => a + b);
    var target = Math.ceil(sum / 2);
    var dp = new Array(target + 1).fill(0);
    for(var i = 0; i < stones.length; i++) {
        for(var j = target; j >= stones[i]; j--) {
            dp[j] = Math.max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return Math.abs(2 * dp[target] - sum);
};