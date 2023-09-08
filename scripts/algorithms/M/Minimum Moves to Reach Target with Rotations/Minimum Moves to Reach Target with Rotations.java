// Runtime: 33 ms (Top 25.8%) | Memory: 45.52 MB (Top 12.9%)

class Solution {
    public int minimumMoves(int[][] grid) {
        
        int n = grid.length;  
        //boolean[][][][] visited = new boolean[n][n][n][n];
        Set<Position> set = new HashSet<>();
       
        Queue<Position> q = new LinkedList<>();
        q.offer(new Position(0,0,0,1));        
        int count = 0;
                
        if(grid[n-1][n-2] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        while(!q.isEmpty()){
            ++count;
            Queue<Position> nextq = new LinkedList<>();
            while(!q.isEmpty()){
                
                Position p = q.poll();

                int r1 = p.getr1();
                int r2 = p.getr2();
                int c1 = p.getc1();
                int c2 = p.getc2();
                
                if(r1 == n-1 && r2 == n-1 && c1 == n-2 && c2==n-1)
                    return count-1;
                
                if(set.contains(p))
                    continue;
                
                if(c1+1 < n && grid[r1] [c1+1] != 1 && c2+1 < n && grid[r2] [c2+1] != 1)
                    nextq.offer(new Position(r1, c1+1, r2, c2+1));
                if(r1+1 < n && grid[r1+1] [c1] != 1 && r2+1 < n && grid[r2+1] [c2] != 1)
                    nextq.offer(new Position(r1+1, c1, r2+1, c2));
                
                if(r1 == r2 && r1+1 < n && r2+1 < n && grid[r1+1][c1] == 0 && grid[r2+1][c2] == 0 && grid[r1+1][c1] == 0)
                    nextq.offer(new Position(r1,c1, r1+1, c1));
                
                if(c1 == c2 && c1+1 < n && c2+1 < n && grid[r1][c1+1] == 0 && grid[r2][c1+1] == 0   && grid[r1][c1+1] == 0)
                    nextq.offer(new Position(r1,c1, r1, c1+1));
                set.add(p);
            }
            q = nextq;
        }
        return -1;
    }
    
    private class Position{
        int r1;
        int c1;
        int r2;
        int c2;
        
        public Position(int r1, int c1, int r2, int c2){
            this.r1 = r1;
            this.r2 = r2;
            this.c1 =c1;
            this.c2 = c2;
        }
        
        public int getr1(){
            return this.r1;
        }
        public int getr2(){
            return this.r2;
        }
        public int getc1(){
            return this.c1;
        }
        public int getc2(){
            return this.c2;
        }
        
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * r1 + c1 + prime *r2 + c2;
            return result;
        }
        
        @Override
        public boolean equals(Object obj) {
            Position p = (Position) obj;
            if(this.r1 == p.getr1() && this.r2 ==p.getr2() && this.c1 == p.getc1() && this.c2==p.getc2())
                return true;
            else
                return false;
        }
    }    
}