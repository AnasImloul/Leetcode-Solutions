class Solution {
    public boolean containsCycle(char[][] grid) {
        int rows = grid.length, cols = grid[0].length;

		// Create a boolean array of same dimensions to keep track of visited cells
        boolean[][] visited = new boolean[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && dfs(grid, visited, i, j, 0, 0, grid[i][j])) {
                    return true;
                }
            }
        }

        return false;
    }
    
    public boolean dfs(
        char[][] grid,
        boolean[][] visited,
        int i,
        int j,
        int prevI,
        int prevJ,
        char c
    ) {
		// Check for out of bounds
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) return false;

		// Check whether the current char matches the previous char
        if (grid[i][j] != c) return false;
		
		// If we stumble upon the same cell, we're guaranteed to have found a cycle!
        if (visited[i][j]) {
            return true;
        }
        
		// Mark the cell as visited
        visited[i][j] = true;
        
		// We want to search in the south direction ONLY IF we didn't come from north
		// Do the same for all four directions
        boolean south = i - prevI != -1;
        boolean north = i - prevI != 1;
        boolean east = j - prevJ != -1;
        boolean west = j - prevJ != 1;
        return
            (south && dfs(grid, visited, i + 1, j, i, j, c)) ||
            (north && dfs(grid, visited, i - 1, j, i, j, c)) ||
            (east && dfs(grid, visited, i, j + 1, i, j, c)) ||
            (west && dfs(grid, visited, i, j - 1, i, j, c));
    }
}
