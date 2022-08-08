class Solution {
    public int swimInWater(int[][] grid) {
        int len = grid.length;
        Map<Integer, int[]> reverseMap = new HashMap<>();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                reverseMap.put(grid[i][j], new int[] { i, j });
            }
        }
        
        int left = grid[0][0]; // answer cannot be less than value of starting position
        int right = len * len - 1;
        
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSwim(grid, reverseMap, mid, len)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    
    boolean canSwim(int[][] grid, Map<Integer, int[]> reverseIndex, int ans, int len) {
        int[] x_diff = { 1, -1, 0, 0 };
        int[] y_diff = { 0, 0, 1, -1 };
        
        // BFS
        Queue<int[]> container = new LinkedList<>();
        container.add(new int[] { 0, 0 });
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        visited[0][0] = true;
            
        while (!container.isEmpty()) {
            int[] curr = container.poll();
            int currVal = grid[curr[0]][curr[1]];
            for (int i = 0; i < 4; i++) {
                int newX = curr[0] + x_diff[i];
                int newY = curr[1] + y_diff[i];
                if (isValidCell(grid, newX, newY, ans) && !visited[newX][newY]) {
                    if (newX == grid.length-1 && newY == grid[0].length-1) {
                        return true;
                    }
                    visited[newX][newY] = true;
                    container.add(new int[] { newX, newY });
                }
            }   
        }
        
        return false;
    }
    
    boolean isValidCell(int[][] grid, int x, int y, int ans) {
	    // check boundary and if grid elevation is greater than evaluated answer
        return !(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] > ans);
    }
}
