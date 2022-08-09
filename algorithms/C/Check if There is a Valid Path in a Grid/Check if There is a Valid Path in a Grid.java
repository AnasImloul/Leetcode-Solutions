class Solution {
    class UF {
        int[] root;
        int[] size;
        
        public UF(int n){
            this.root = new int[n];
            this.size = new int[n];
            
            for(int i = 0; i < n; i++){
                this.root[i] = i;
                this.size[i] = 1;
            }
        }
        
        public int find(int x){
            while(x != root[x]){
                root[x] = root[root[x]];
                x = root[x];
            }
            return x;
        }
        
        public void union(int x, int y){
            int rx = find(x);
            int ry = find(y);
            
            if(rx == ry) return;
            
            if(size[rx] > size[ry]){
                root[ry] = rx;
                size[rx] += size[ry];
            }else{
                root[rx] = ry;
                size[ry] += size[rx];
            }
        }
        
        public boolean isConnected(int x, int y){
            return find(x) == find(y);
        }
    }
    
    public boolean hasValidPath(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        UF uf = new UF(n * m);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int left = i * m + j - 1;
                int right = i * m + j + 1;
                int up = (i - 1) * m + j;
                int down = (i + 1) * m + j;
                int u = i * m + j;
                if(grid[i][j] == 1){
                    // union left and right 
                    // if left has right interface
                    // (grid[i][j + 1] == 1 || grid[i][j + 1] == 4 || grid[i][j + 1] == 6)
                    if(j >= 1 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)){
                        uf.union(u, left);
                    }
                    // if right has left interface
                    if(j < m - 1 && grid[i][j + 1] % 2 == 1){
                        uf.union(u, right);
                    }
                }else if(grid[i][j] == 2){
                    // up and down
                    // up has down
                    if(i >= 1 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4)){
                        uf.union(u, up);
                    }
                    // down has up
                    if(i < n - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)){
                        uf.union(u, down);
                    }
                }else if(grid[i][j] == 3){
                    // left and down
                    // left has right
                    if(j >= 1 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)){
                        uf.union(u, left);
                    }
                    // down has up
                    if(i < n - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)){
                        uf.union(u, down);
                    }
                }else if(grid[i][j] == 4){
                    // right and down
                    // right has left
                    if(j < m - 1 && grid[i][j + 1] % 2 == 1){
                        uf.union(u, right);
                    }
                    // down has up
                    if(i < n - 1 &&  (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)){
                        uf.union(u, down);
                    }
                }else if(grid[i][j] == 5){
                    // up and left
                    // up has down
                    if(i >= 1 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4)){
                        uf.union(u, up);
                    }
                    
                    // left has righ
                    if(j >= 1 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)){
                        uf.union(u, left);
                    }
                }else if(grid[i][j] == 6){
                    // up and right
                    // up has down
                    if(i >= 1 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4)){
                        uf.union(u, up);
                    }
                    // right has left
                    if(j < m - 1 &&  grid[i][j + 1] % 2 == 1){
                        uf.union(u, right);
                    }
                }
            }
        }
        
        return uf.isConnected(0, n * m - 1);
    }
}
