class Solution {
    public int minOperations(int[][] grid, int x) {
        int[] arr = new int[grid.length * grid[0].length];
        int index = 0;
        
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                arr[index++] = grid[i][j];
            }
        }
        
        Arrays.sort(arr);
        int median = arr[(arr.length - 1) / 2];
        int steps = 0;
        
        for (int num : arr) {
            if (num == median) {
                continue;
            }
            
            if (Math.abs(num - median) % x != 0) {
                return -1;
            }
            
            steps += (Math.abs(num - median) / x);
        }
        
        return steps;
    }
}
