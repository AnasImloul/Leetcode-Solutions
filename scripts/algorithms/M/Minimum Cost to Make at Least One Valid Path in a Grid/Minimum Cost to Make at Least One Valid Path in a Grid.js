const minCost = function (grid) {
	const m = grid.length,
		n = grid[0].length,
		checkPos = (i, j) =>
			i > -1 && j > -1 && i < m && j < n && !visited[i + "," + j],
		dir = { 1: [0, 1], 2: [0, -1], 3: [1, 0], 4: [-1, 0] },
		dfs = (i, j) => {
			if (!checkPos(i, j)) return false;
			if (i === m - 1 && j === n - 1) return true;
			visited[i + "," + j] = true;
			next.push([i, j]);
			return dfs(i + dir[grid[i][j]][0], j + dir[grid[i][j]][1]);
		},
		visited = {};
	let changes = 0, cur = [[0, 0]], next;
	while (cur.length) {
		next = [];
		for (const [i, j] of cur) if (dfs(i, j)) return changes;
		changes++;
		cur = [];
		next.forEach(pos => {
			for (let d = 1; d < 5; d++) {
				const x = pos[0] + dir[d][0],
					y = pos[1] + dir[d][1];
				if (checkPos(x, y)) cur.push([x, y]);
			}
		});
	}
};