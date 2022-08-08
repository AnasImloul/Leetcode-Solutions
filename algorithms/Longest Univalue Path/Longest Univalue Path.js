var longestUnivaluePath = function(root) {
	let max = 0;
	const dfs = (node = root, parentVal) => {
		if (!node) return 0;
		const { val, left, right } = node;
		const leftPath = dfs(left, val);
		const rightPath = dfs(right, val);

		max = Math.max(max, leftPath + rightPath);
		return val === parentVal 
			? Math.max(leftPath, rightPath) + 1
			: 0;
	};

	dfs();
	return max;
};