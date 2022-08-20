// Runtime: 13 ms (Top 59.97%) | Memory: 53.7 MB (Top 81.02%)

class Solution {
    private static int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    public int shortestBridge(int[][] grid) {
        boolean[][] visited=new boolean[grid.length][grid[0].length];
        LinkedList<Pair> queue=new LinkedList<Pair>();
        boolean found=false;
        for(int i=0;i<grid.length && !found;i++){
            for(int j=0;j<grid[0].length && !found;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,queue,visited);
                    found=true;
                }
            }
        }
        int level=0;
        while(queue.size()>0){
            int size=queue.size();
            while(size-- >0){
                Pair pair=queue.poll();
                for(int k=0;k<4;k++){
                    int rowDash=pair.row+dirs[k][0];
                    int colDash=pair.col+dirs[k][1];
                    if(rowDash<0 || colDash<0 || rowDash>=grid.length || colDash>=grid[0].length ||
                       visited[rowDash][colDash]==true )continue;
                    if(grid[rowDash][colDash]==1) return level;
                    queue.add(new Pair(rowDash,colDash));
                    visited[rowDash][colDash]=true;
                }
            }
            level++;
        }
        return -1;
    }
    private void dfs(int[][] grid,int i,int j,LinkedList<Pair> queue,boolean[][] visited){
        visited[i][j]=true;
        queue.add(new Pair(i,j));
        for(int k=0;k<4;k++){
            int rowDash=i+dirs[k][0];
            int colDash=j+dirs[k][1];
        if(rowDash<0 || colDash<0 || rowDash>=grid.length || colDash>=grid[0].length ||
           visited[rowDash][colDash]==true || grid[rowDash][colDash]==0)continue;
        dfs(grid,rowDash,colDash,queue,visited);
        }
    }
    static class Pair{
        int row;
        int col;
        public Pair(int row,int col){
            this.row=row;
            this.col=col;
        }
    }
}