// Runtime: 416 ms (Top 88.89%) | Memory: 127.50 MB (Top 100.0%)

var matrixRankTransform = function(matrix) {
    const n = matrix.length;
	const m = matrix[0].length;
    //max rank found in x/y lists where yMax[4] would represent the max value found in row index 4;
	const yMax = [];
	const xMax = [];
	const valueToCoords = {};
    
	for (let y = 0; y < n; ++y) {
		for (let x = 0; x < m; ++x) {
			const value = matrix[y][x];
			if (!valueToCoords[value]) valueToCoords[value] = [];
			valueToCoords[value].push([x, y]);
		}
	}
    
	const sortedKeys = Object.keys(valueToCoords).sort((x, y) => x - y);
    
	let parent;
    
	function find(target) {
		if (parent[target] == null) parent[target] = target;
		parent[target] = parent[parent[target]];
		return parent[target] === target ? target : find(parent[target]);
	}
    
	for (const value of sortedKeys) {
		const list = valueToCoords[value];
		//find cycles
		if (list.length > 1) {
			parent = {};
			let ranks = {};
			for (const [x, y] of list) {
				let px = find(x);
				let py = find(y + n); //have to avoid collisions between y and x keys when they are being used to identify the row/col
				parent[px] = py; //bind all the rows and columns together into union by always making the parent of x as y
				ranks[py] = Math.max(
					xMax[x] ?? 0,
					yMax[y] ?? 0,
					ranks[py] ?? 0,
					ranks[px] ?? 0,
				);
			}
			for (const [px, py] of list) {
				const rank = Math.max(ranks[find(px)]) + 1; //since we always bind x to y, we can just find x
				xMax[px] = yMax[py] = matrix[py][px] = rank;
			}
		} else {
			for (const [px, py] of list) {
				const rank = Math.max(yMax[py] ?? 0, xMax[px] ?? 0) + 1;
				xMax[px] = yMax[py] = matrix[py][px] = rank;
			}
		}
	}
    
	return matrix;
};
