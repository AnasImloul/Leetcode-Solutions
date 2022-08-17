class Solution {
    int dir[][] = new int[][]{
        {1, 0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    private int countArea(int grid[][], int i, int j, int num){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length)
            return 0;
        
        if(grid[i][j] != 1) return 0;
        
        grid[i][j] = num;
        int count = 0;
        for(int d[] : dir){
            count += countArea(grid, i + d[0], j + d[1], num);
        }
        
        return 1 + count;
    }
    
    private void fillDP(int grid[][], int dp[][], int i, int j, int count, int num){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) return ;
        
        if(grid[i][j] != num) return;
        
        if(dp[i][j] != 0) return ;
        dp[i][j] = count;
        for(int d[] : dir){
            fillDP(grid, dp, i + d[0], j + d[1], count, num);
        }
        
    }
    
    
    public int largestIsland(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int dp[][] = new int[n][m];
        
        int num = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    ++num;
                    int count1 = countArea(grid, i, j, num);
                    fillDP(grid, dp, i, j, count1, num);
                }
            }
        }
        
        int max = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] != 0) continue;
                int val = 1;
                Set<Integer> set = new HashSet<>();
                for(int d[] : dir){
                    int newRow = i + d[0];
                    int newCol = j + d[1];
                    
                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
                    if(set.contains(grid[newRow][newCol])) continue;
                    
                    val += dp[newRow][newCol];
                    set.add(grid[newRow][newCol]);
                }
                max = Math.max(max, val);
            }
        }
        
        if(max == 0) return n * m;
        return max;
        
    }
}
