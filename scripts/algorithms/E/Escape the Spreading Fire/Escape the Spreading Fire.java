// Runtime: 12 ms (Top 89.41%) | Memory: 45.50 MB (Top 60.0%)

class Solution {
    public int maximumMinutes(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        int[][] times = new int[m][n];
        for(int[] row : times) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        int[] dir = new int[]{-1, 0, 1, 0, -1};
        
		// Queue for running BFS
        Deque<int[]> fires = new ArrayDeque<>();
		
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    times[row][col] = 0;
                    fires.offer(new int[]{row, col});
                }
            }
        }
        
        int time = 1;
        while(!fires.isEmpty()) {
            int size = fires.size();
            
            for(int i = 0; i < size; i++) {
                int[] pos = fires.poll();
                
                for(int j = 0; j < 4; j++) {
                    int x = pos[0] + dir[j];
                    int y = pos[1] + dir[j + 1];
                    
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0 && times[x][y] == Integer.MAX_VALUE) {
                        times[x][y] = time;
                        fires.offer(new int[]{x, y});
                    }
                }
            }
            
            time++;
        }
        
        fires.clear();
        
        int ans = Integer.MAX_VALUE;
        fires.offer(new int[]{0, 0});
        grid[0][0] = 2;

        time = 1;
        while(!fires.isEmpty() && grid[m - 1][n - 1] == 0) {
            int size = fires.size();
            
            int t = Integer.MIN_VALUE;
            
            for(int i = 0; i < size && grid[m - 1][n - 1] == 0; i++) {
                int[] pos = fires.poll();
            
                for(int j = 0; j < 4 && grid[m - 1][n - 1] == 0; j++) {
                    
                    int x = pos[0] + dir[j];
                    int y = pos[1] + dir[j + 1];

                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0 && times[x][y] >= time) {
                        if (x == m - 1 && y == n - 1) {
                            t = times[x][y] - time;
                            grid[x][y] = 2;
                            break;
                        }

                        grid[x][y] = 2;
                        fires.offer(new int[]{x, y});
                        
						// if times[x][y] == Integer.MAX_VALUE, fire will never reach this cell and it will contribute maximum wait time
                        t = Math.max(t, times[x][y] == Integer.MAX_VALUE ? 1000000000 : times[x][y] - time - 1);
                    }
                }
            }
            
            ans = Math.min(ans, t);
            
            time++;
        }
        
		// You can never reach the safe house
        if (grid[m - 1][n - 1] != 2) {
            return -1;
        }
        
		// you can reach the safe house but fire can not
        if (times[m - 1][n - 1] == Integer.MAX_VALUE) {
            return 1000000000;
        }
        
        return ans == Integer.MAX_VALUE || ans == Integer.MIN_VALUE ? -1 : ans;
    }
}
