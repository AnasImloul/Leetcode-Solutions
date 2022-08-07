var leastBricks = function(wall) {
	const hash = wall.reduce((map, row) => {
		let sum = 0;

		for (let index = 0; index < row.length - 1; index++) {
			sum += row[index];
			const hashCount = map.get(sum) ?? 0;
			map.set(sum, hashCount + 1);
		}
		return map;
	}, new Map());

	let result = wall.length;
	hash.forEach(value => result = Math.min(result, wall.length - value));

	return result;
};