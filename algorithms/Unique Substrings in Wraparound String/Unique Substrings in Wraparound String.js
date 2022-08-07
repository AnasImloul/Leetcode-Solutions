var findSubstringInWraproundString = function(p) {
	const dp = Array(26).fill(0);
	const origin = 'a'.charCodeAt(0);
	let count = 0;

	for (let index = 0; index < p.length; index++) {
		const code = p.charCodeAt(index);
		const preCode = p.charCodeAt(index - 1);
		const pos = code - origin;

		count = code - preCode === 1 || preCode - code === 25
			? count + 1
			: 1;

		dp[pos] = Math.max(count, dp[pos]);
	}

	return dp.reduce((total, count) => total + count);
};