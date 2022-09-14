// Runtime: 150 ms (Top 49.61%) | Memory: 121.4 MB (Top 10.85%)
class Solution {
    int[][] dir = new int[][]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    public int latestDayToCross(int row, int col, int[][] cells) {
        int grid[][] = new int[row][col];
        int low = 0, high = cells.length - 1;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            for(int i = 0; i <= mid; i++)
                grid[cells[i][0] -1][cells[i][1] - 1] = 1;

            if(helper(grid, new boolean[row][col])){
                ans = mid;
                low = mid + 1;
            }

            else high = mid - 1;

            for(int i = 0; i < grid.length; i++)
                for(int j = 0; j < grid[i].length; j++)
                    grid[i][j] = 0;
        }

        return ans + 1;
    }

    public boolean helper(int[][] grid, boolean[][] visited){
        for(int i = 0; i < grid[0].length; i++)
            if(grid[0][i] == 0 && !visited[0][i] &&safe(0, i, grid, visited)) return true;
        return false;
    }

    public boolean safe(int i, int j, int[][] cells, boolean[][] visited){
        if(i < 0 || j < 0 || i >= visited.length || j >= visited[i].length || visited[i][j] || cells[i][j] == 1) return false;
        if(i == cells.length - 1 && j < cells[i].length && cells[i][j] == 0) return true;

        visited[i][j] = true;
        for(int k = 0; k < dir.length; k++)
            if(safe(i + dir[k][0], j + dir[k][1], cells, visited)) return true;
        return false;
    }
}