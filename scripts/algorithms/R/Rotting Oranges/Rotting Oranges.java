class Solution {
    class Pair{
        int i;
        int j;
        int t;
        
        public Pair(int i,int j,int t){
            this.i = i;
            this.j = j;
            this.t = t;
        }
    }
    int ans = 0;
    final int[][] dir = {{-1,0},{1,0},{0,-1},{0,1}};
    public int orangesRotting(int[][] grid) {
        int countFresh = 0;
        Queue<Pair> q = new LinkedList<>();
        for(int i=0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == 2){
                    q.offer(new Pair(i,j,0));
                }else if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }
        int count = 0;
        while(q.size() != 0){
            Pair temp = q.poll();
            ans = Math.max(ans,temp.t);
            for(int[] d : dir){
                int r = temp.i + d[0];
                int c = temp.j + d[1];
                int t = temp.t +1;
                if(r >= 0 && c >= 0 && r <grid.length && c < grid[0].length && grid[r][c] == 1){
                    q.offer(new Pair(r,c,t));
                    grid[r][c] = 2;
                    count++;
                }
            }
        }
        if(count != countFresh) return -1;
        return ans;
    }
}