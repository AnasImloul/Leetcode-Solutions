// Runtime: 4 ms (Top 57.93%) | Memory: 42.6 MB (Top 71.50%)
class Solution {
    public int orangesRotting(int[][] grid) {
        int freshOranges = 0;
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[]{i, j});
                }
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        int[][] dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int time = 0;
        while(!queue.isEmpty() && freshOranges > 0) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] pop = queue.poll();
                for (int[] dir : dirs) {
                    int row = dir[0] + pop[0];
                    int col = dir[1] + pop[1];
                    if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1) {
                        queue.add(new int[]{row, col});
                        grid[row][col] = 2;
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        return freshOranges == 0 ? time : -1;
    }
}