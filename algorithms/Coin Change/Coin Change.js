var change = function(amount, coins) {
	const dp = Array(amount + 1).fill(0);
	dp[0] = 1;

	coins.forEach(coin => {
		for (let num = coin; num <= amount; num++) {
			dp[num] += dp[num - coin];
		}
	});
	return dp[amount];
};