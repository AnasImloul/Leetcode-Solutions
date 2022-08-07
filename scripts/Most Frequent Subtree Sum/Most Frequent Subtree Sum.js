var findFrequentTreeSum = function(root) {
	const hash = new Map();
	const result = [];
	let max = 0;
	const dfs = (node = root) => {
		if (!node) return 0;
		const { left, right, val } = node;
		const sum = val + dfs(left) + dfs(right);
		const count = hash.get(sum) ?? 0;
		hash.set(sum, count + 1);
		max = Math.max(max, count + 1);
		return sum;
	};

	dfs();
	hash.forEach((value, key) => value === max && result.push(key));
	return result;
};