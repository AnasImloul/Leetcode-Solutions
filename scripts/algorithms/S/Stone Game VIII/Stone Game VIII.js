var stoneGameVIII = function(stones) {
    let prefix = Array(stones.length);
    for (let i = 0; i < stones.length; i++) prefix[i] = stones[i] + (prefix[i - 1] || 0);
    
    let dp = Array(stones.length).fill(0);
    function game(idx) {
        if (dp[idx]) return dp[idx];
        if (idx >= stones.length) return 0;
        let skip = game(idx + 1);
        let take = prefix[idx] - skip;
        dp[idx] = take;
        // Both Alice and Bob must maximize their scores, which would maximize the difference for Alice and minimize the difference for Bob
        // Return the max score of either removing stones from the current idx or skipping to the next idx
        return !skip ? take : Math.max(skip, take);
    }

    return game(1);
};
