class Solution {
    
    private static final int[][] DIR = new int[][]{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    public int containVirus(int[][] isInfected) {
        int m = isInfected.length, n = isInfected[0].length;
        int ans = 0;
        
        while( true ) {
            // infected regions, sorted desc according to the number of nearby 
            // uninfected nodes
            PriorityQueue<Region> pq = new PriorityQueue<Region>();
            // already visited cells
            boolean[][] visited = new boolean[m][n];
            
            // find regions
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    
                    // if current cell is infected, and it's not visited
                    if( isInfected[i][j] != 1 || visited[i][j] ) 
                        continue;
                    
                    // we found a new region, dfs to find all the infected
                    // and uninfected cells in the current region
                    Region reg = new Region();
                    dfs(i, j, reg, isInfected, visited, new boolean[m][n], m, n);
                    
                    // if there are some uninfected nodes in this region, 
                    // we can contain it, so add it to priority queue
                    if( reg.uninfected.size() != 0)
                        pq.offer(reg);
                }
            }
            
            // if there are no regions to contain, break
            if( pq.isEmpty() )
                break;

            // Contain region with most uninfected nodes
            Region containReg = pq.poll();
            ans += containReg.wallsRequired;
            
            // use (2) to mark a cell as contained
            for(int[] cell : containReg.infected)
                isInfected[cell[0]][cell[1]] = 2;
            
            // Spread infection to uninfected nodes in other regions
            while( !pq.isEmpty() ) {
                Region spreadReg = pq.poll();
                
                for(int[] cell : spreadReg.uninfected)
                    isInfected[cell[0]][cell[1]] = 1;
            }
        }
        return ans;
    }
    
    private void dfs(int i, int j, Region reg, int[][] grid, boolean[][] visited, boolean[][] uninfectedVis, int m, int n) {
        visited[i][j] = true;
        reg.addInfected(i, j);
        
        for(int[] dir : DIR) {
            int di = i + dir[0];
            int dj = j + dir[1];
            
            // continue, if out of bounds OR contained OR already visited
            if( di < 0 || dj < 0 || di == m || dj == n || grid[di][dj] == 2 || visited[di][dj] )
                continue;
            
            // if neighbour node is not infected
            if( grid[di][dj] == 0 ) {
                // a wall will require to stop the spread from cell (i,j) to (di, dj)
                reg.wallsRequired++;
                
                // if this uninfected node is not already visited for current region
                if( !uninfectedVis[di][dj] ) {
                    uninfectedVis[di][dj] = true;
                    reg.addUninfected(di, dj);
                }
            } else 
                dfs(di, dj, reg, grid, visited, uninfectedVis, m, n);
        }
    }
}
class Region implements Comparable<Region> {
    public List<int[]> infected;
    public List<int[]> uninfected;
    public int wallsRequired;
    
    public Region() {
        infected = new ArrayList();
        uninfected = new ArrayList();
    }
    
    public void addInfected(int row, int col) {
        infected.add(new int[]{ row, col });
    }
    
    public void addUninfected(int row, int col) {
        uninfected.add(new int[]{ row, col });
    }
    
    @Override
    public int compareTo(Region r2) {
        return Integer.compare(r2.uninfected.size(), uninfected.size());
    }
}

