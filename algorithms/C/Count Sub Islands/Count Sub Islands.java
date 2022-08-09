class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int m = grid1.length;
        int n = grid1[0].length;
        boolean[][] vis = new boolean[m][n];
        int count = 0;
        int[] dir = {1, 0, -1, 0, 1};
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid2[i][j] == 0 || vis[i][j])
                    continue;
                
                Queue<int[]> queue = new LinkedList<>();
                boolean flag = true;
                vis[i][j] = true;
                
                queue.add(new int[] {i, j});
                
                while(!queue.isEmpty()) {
                    int[] vtx = queue.remove();
                    
                    if(grid1[vtx[0]][vtx[1]] == 0)
                        flag = false;
                    
                    for(int k = 0; k < 4; ++k) {
                        int x = vtx[0] + dir[k];
                        int y = vtx[1] + dir[k + 1];
                        
                        if(x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1 && !vis[x][y]) {
                            vis[x][y] = true;
                            
                            queue.add(new int[] {x, y});
                        }
                    }
                }
                
                if(flag)
                    ++count;
            }
        }
        
        return count;
    }
}
