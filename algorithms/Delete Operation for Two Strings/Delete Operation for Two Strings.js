var minDistance = function(word1, word2) {
	const WORD1_LEN = word1.length;
	const WORD2_LEN = word2.length;
	const dp = Array(WORD1_LEN + 1).fill('').map(() => Array(WORD2_LEN + 1).fill(0));

	for (let index = 1; index <= WORD1_LEN; index++) {
		for (let j = 1; j <= WORD2_LEN; j++) {
			dp[index][j] = word1[index - 1] === word2[j - 1]
				? dp[index - 1][j - 1] + 1
				: Math.max(dp[index - 1][j], dp[index][j - 1]);
		}
	}

	return WORD1_LEN + WORD2_LEN - 2 * dp[WORD1_LEN][WORD2_LEN];
};