class Solution {
    class Point {
        int x, y;
        public Point(int x, int y){
            this.x=x;
            this.y=y;
        }
    }
    int[][] dist;
    int n,ans;
    int[] dx={0, 0, +1, -1};
    int[] dy={+1, -1, 0, 0};
    public int maxDistance(int[][] grid) {
        n=grid.length;
        dist = new int[n][n];
        Queue<Point> q = new LinkedList<>();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0) dist[i][j]=2*1000*1000*1000;
                else {
                    dist[i][j]=0;
                    q.add(new Point(i, j)); // multisource on grid[i][j] = 1
                }
            }
        }
        ans=-1;
        while(!q.isEmpty()){
            Point p = q.poll();
            int x = p.x;
            int y = p.y;
            for (int k = 0; k < 4; k++) {
                int r=dx[k]+x;
                int c=dy[k]+y;
                if (valid(r,c)&&grid[r][c]==0&&dist[r][c]>dist[x][y]+1){
                    dist[r][c]=dist[x][y]+1;
                    Point newP = new Point(r,c);
                    q.add(newP);
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                ans=Math.max(ans,dist[i][j]); // Manhattan distance is the same as the distance on the grid in general 
            }
        }
        if (ans==0||ans==2*1000*1000*1000) ans=-1;
        return ans;
    }
    public boolean valid(int r, int c){
        return r>=0&&c>=0&&r<n&&c<n;
    }
}
