// Runtime: 184 ms, faster than 95.24%
// Memory Usage: 50.9 MB, less than 100.00%
var hasValidPath = function(grid) {
	if (grid[0][0] === 5) return false;

	const M = grid.length, N = grid[0].length;
	const SEGMENTS = {
		1: {dirs: [[0,-1], [0,1]], adjs: [[1,4,6], [1,3,5]]},
		2: {dirs: [[-1,0], [1,0]], adjs: [[2,3,4], [2,5,6]]},
		3: {dirs: [[0,-1], [1,0]], adjs: [[1,4,6], [2,5,6]]},
		4: {dirs: [[0,1],  [1,0]], adjs: [[1,3,5], [2,5,6]]},
		5: {dirs: [[-1,0], [0,-1]],adjs: [[2,3,4], [1,4,6]]},
		6: {dirs: [[-1,0], [0,1]], adjs: [[2,3,4], [1,3,5]]}
	}
	let path = Array.from({length: grid.length}, el => new Uint16Array(grid[0].length))
	let y = 0, x = 0;

	function getNextSegment(segment, y, x) {
		let dir = 0;
		let ny = y + SEGMENTS[segment].dirs[dir][0];
		let nx = x + SEGMENTS[segment].dirs[dir][1];
		if (ny < 0 || ny >= M || nx < 0 || nx >= N || path[ny][nx]) {
			dir = 1;
			ny = y + SEGMENTS[segment].dirs[dir][0];
			nx = x + SEGMENTS[segment].dirs[dir][1];
		}
		return {dir, ny, nx}
	}

	function isValid(y, x) {
		for (let i = 0; i < M*N; i++) {
			if (y == M-1 && x == N-1) return true;
			path[y][x] = i+1;
			let cur = grid[y][x];
			let next = getNextSegment(cur, y, x);
			if (next.ny >= M || next.nx >= N) return false;
			if (!SEGMENTS[cur].adjs[next.dir].includes(grid[next.ny][next.nx])) return false;
			y = next.ny;
			x = next.nx;
		}
		return false
	}

	if (grid[0][0] !== 4) return isValid(y, x);
	path[0][0] = 1;
	return isValid(y, x+1) || isValid(y+1, x);
};
