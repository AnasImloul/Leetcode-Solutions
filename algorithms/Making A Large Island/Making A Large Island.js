var largestIsland = function(grid) {
    const n = grid.length
	/**
	 *  Create the merge find (union find) structure --> https://www.youtube.com/watch?v=ibjEGG7ylHk
	 *  For this case, we will form the sets at once, already assigning the same representative to all members.
	 *  Thus, we can use this simplistic implementation without path compression and find(i) = mf[i]
	 */
    const mf = []
    for (let i = 0; i < n*n; i++) {
        mf.push(i)
    }
	// Helper that converts coordinates to array position
    const toPos = (r, c) => r * n + c
	// Recursively set the merge find structure to represent the islands' map
    const merge = (r, c, repr) => {
        mf[toPos(r, c)] = repr // Merge coordinate
		/**
		 *  Visit neighbors. To visit a neighboring coordinate we first check for:
		 *  Boundaries (coordinates stay within matrix limits)
		 *  Neighbor is land (contains a 1)
		 *  We didn't visit it already (has different representative)
		 */
        if (r > 0 && grid[r-1][c] === 1 && mf[toPos(r-1, c)] !== repr) { // Top
            merge(r-1, c, repr)
        }
        if (c < n-1 && grid[r][c+1] === 1 && mf[toPos(r, c+1)] !== repr) { // Right
            merge(r, c+1, repr)
        }
        if (r < n-1 && grid[r+1][c] === 1 && mf[toPos(r+1, c)] !== repr) { // Bottom
            merge(r+1, c, repr)
        }
        if (c > 0 && grid[r][c-1] === 1 && mf[toPos(r, c-1)] !== repr) { // Left
            merge(r, c-1, repr)
        }
    }
	/**
	 *  For each land (1) position that wasn't already merged into a set,
	 *  we define a new set with its neighbors.
	 */
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const pos = toPos(i, j)
            if (grid[i][j] === 1 && mf[pos] === pos) {
                merge(i, j, pos)
            } 
        }
    }
	/**
	 *  We can now calculate the surface of every island by counting the number of cells
	 *  with the same representative.
	 */
    const count = Array(n*n).fill(0)
    mf.forEach(el => count[el]++)
    /**
	 *  Now we have to decide on which sea (0) should be toggled into land (1).
	 *  For this we save, for each zero, which sets it is contact with. Once this is done,
	 *  we can calculate the entire surface by suming 1 + the surface of all touching sets.
	 *  Again, to add the neighbor set to the store, we need to check that it is a one, that we
	 *  are within the boundaries, and that it was not already marked as neighbor.
	 *  We store the maximum surface found, which is the final solution.
	 */
    let maxSurface = 0
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] === 0) {
                const touching = []
                let currentSurface = 1
                if (r > 0 && grid[r-1][c] === 1 && !touching.includes(mf[toPos(r-1, c)])) { // Top
                    touching.push(mf[toPos(r-1,c)])
                }
                if (c < n-1 && grid[r][c+1] === 1 && !touching.includes(mf[toPos(r, c+1)])) { // Right
                    touching.push(mf[toPos(r,c+1)])
                }
                if (r < n-1 && grid[r+1][c] === 1 && !touching.includes(mf[toPos(r+1, c)])) { // Bottom
                    touching.push(mf[toPos(r+1, c)])
                }
                if (c > 0 && grid[r][c-1] === 1 && !touching.includes(mf[toPos(r, c-1)])) { // Left
                    touching.push(mf[toPos(r, c-1)])
                }
                touching.forEach(set => currentSurface += count[set])
                if (currentSurface > maxSurface) {
                    maxSurface = currentSurface
                }
            } 
        }
    }
    /**
	 * If maxSurface remained at zero, it means the input is a matrix of ones.
	 */
    if (maxSurface > 0) { return maxSurface }
    return n*n
}
