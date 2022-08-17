/**
 * The dynamic programming solution.
 * 
 * Time Complexity:  O(m*n)
 * Space Complexity: O(1)
 * 
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
	const m = dungeon.length
	const n = dungeon[0].length

	const ii = m - 1
	const jj = n - 1

	for (let i = ii; i >= 0; i--) {
		for (let j = jj; j >= 0; j--) {
			if (i < ii || j < jj) {
				const hc = dungeon[i][j]

				const hp1 = (i < ii) ? Math.min(hc, hc + dungeon[i + 1][j]) : -Infinity
				const hp2 = (j < jj) ? Math.min(hc, hc + dungeon[i][j + 1]) : -Infinity

				dungeon[i][j] = Math.max(hp1, hp2)
			}
		}
	}

	return Math.max(1 - dungeon[0][0], 1)
}
