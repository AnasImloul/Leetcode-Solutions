class Solution {
    int[]parent;
    int[]rank;
    int[]size;
    int m;
    int n;
    public int[] hitBricks(int[][] grid, int[][] hits) {
        m = grid.length;
        n = grid[0].length;
        parent = new int[m * n + 1];
        rank = new int[m * n + 1];
        size = new int[m * n + 1];
        for(int i=0;i<parent.length;i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
        
        //Logic Start
        for(int []hit : hits){          //remove bricks from grid
            int x = hit[0];
            int y = hit[1];
            if(grid[x][y] == 1){
                grid[x][y] = 2;
            }
        }
        
        for(int i=0;i<m;i++){     //union of all 1's
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    handleUnion(grid,i,j);
                }
            }
        }
        
        int[]res = new int[hits.length];
        
        for(int i=hits.length-1;i>=0;i--){      //Add Bricks where they were and calculate size
            int x = hits[i][0];
            int y = hits[i][1];
            
            if(grid[x][y] == 2){
                int bricksZ = size[find(0)];
                grid[x][y] = 1;
                handleUnion(grid,x,y);
                int newBricks = size[find(0)];
                
                if(newBricks > bricksZ){
                    res[i] = newBricks - bricksZ - 1;
                }
            }
        }
        return res;
    }
    
    int[][]dirs = {{0,-1},{1,0},{0,1},{-1,0}};
    public void handleUnion(int[][]grid,int i,int j){
        int bno = i*n + j + 1;
        for(int[]dir : dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if(ni >= 0 && ni<m && nj >= 0 && nj < n && grid[ni][nj] == 1){
                int nbno = ni*n + nj + 1;
                union(bno,nbno);
            }
        }
        if(i == 0){
            union(0,bno);
        }
    }
    
    public void union(int X,int Y){
        int x = find(X);
        int y = find(Y);
        
        if(x == y){
            return;
        }
        
        if(rank[x] < rank[y]){
            parent[x] = y;
            size[y] += size[x];
        }else if(rank[y] < rank[x]){
            parent[y] = x;
            size[x] += size[y];
        }else{
            parent[y] = x;
            rank[x]++;
            size[x] += size[y];
        }
        
        
    }
    public int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
}
