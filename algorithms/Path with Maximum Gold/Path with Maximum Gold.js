var getMaximumGold = function(grid) {
    let max = 0;
    
	// This is our internal dfs function that will search all possible directions from a cell
    const mine = (x, y, n) => {
	    // We can't mine any gold if the position is out of the grid, or the cell doesnt have any gold
        if (x < 0 || y < 0 || x > grid.length - 1 || y > grid[x].length - 1 || grid[x][y] == 0) return 0;
		
		// Save the temp value so we can mark the cell as visited
        let temp = grid[x][y];
        grid[x][y] = 0;
        
		// Try mining left, right, up, and down from the current position, 
		// bringing along the gold total that was found in the current cell
        mine(x + 1, y, n + temp);
        mine(x - 1, y, n + temp);
        mine(x, y + 1, n + temp);
        mine(x, y - 1, n + temp);
        
		// After we've tried all directions reset cell to have its original value,
		// so it can be mined from a different starting point
        grid[x][y] = temp;
        
		// Update the max based on the mining done up until the current cell
        max = Math.max(max, n + temp);
    }
	
	// We need to run this dfs function through every potential starting point
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            mine(i, j, 0);
        }
    }
    return max;
    
};
