// Runtime: 137 ms (Top 100.0%) | Memory: 61.10 MB (Top 22.22%)

var minCost = function(grid) {
    const n = grid.length;
	const m = grid[0].length;
	const dns = [
		[0, 0], // unused, just put here to make reading signs easier
		[1, 0],
		[-1, 0],
		[0, 1],
		[0, -1],
	];
	const visited = new Set();
	const q = new MinPriorityQueue();
	q.enqueue([0, 0], 0);
	while (q.size()) {
		const { element, priority: changes } = q.dequeue();
		const [x, y] = element;
		if (x === m - 1 && y === n - 1) {
			return changes;
		}
		const key = x + y * m;
		if (visited.has(key)) continue;
		visited.add(key);
		//calculate the direction of the sign and then use it to determine if a change was made whilst pathfinding
		const sign = grid[y][x];
		const sx = dns[sign][0] + x;
		const sy = dns[sign][1] + y;
		for (let i = 1; i < 5; ++i) {
			const nx = dns[i][0] + x;
			const ny = dns[i][1] + y;
			if (grid[ny]?.[nx] && !visited.has(ny * m + nx)) {
				const nextChange = sx === nx && sy === ny ? changes : changes + 1;
				q.enqueue([nx, ny], nextChange);
			}
		}
	}
};
