// Runtime: 49 ms (Top 40.43%) | Memory: 53.4 MB (Top 83.19%)
class Solution {

    int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    private boolean isValid(int i,int j,int n,int m) {
        return i<n && j<m && i>=0 && j>=0;
    }

    private boolean isValidDirection(int [][]grid,int []currEle,int nx,int ny) {
        int nextX=currEle[0],nextY = currEle[1];
        int n =grid.length,m = grid[0].length;

        switch(grid[currEle[0]][currEle[1]]) {
            case 1: nextY++; break;
            case 2: nextY--; break;
            case 3: nextX++; break;
            case 4: nextX--; break;
        }

        return nextX==nx && nextY==ny;
    }

    public int minCost(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        int dist[][] = new int[n][m];
        boolean vis[][] = new boolean[n][m];

        LinkedList<int[]> queue = new LinkedList<>(); // for performing 01 BFS

        for(int i=0;i<n;i++)
            Arrays.fill(dist[i],Integer.MAX_VALUE);

        queue.add(new int[]{0,0});
        dist[0][0]=0;

        while(!queue.isEmpty()) {

            int[] currEle = queue.remove();
            vis[currEle[0]][currEle[1]] = true;

            for(int[] currDir:dirs) {

                    int nx = currDir[0]+currEle[0];
                    int ny = currDir[1]+currEle[1];
                    if(isValid(nx,ny,n,m) && vis[nx][ny]==false) {

                        if(isValidDirection(grid,currEle,nx,ny)) {
                            dist[nx][ny] = Math.min(dist[nx][ny],dist[currEle[0]][currEle[1]]);
                            queue.add(0,new int[]{nx,ny});
                        }
                        else {
                        dist[nx][ny] = Math.min(dist[nx][ny],1+dist[currEle[0]][currEle[1]]);
                            queue.add(new int[]{nx,ny});
                        }
                    }
            }

        }

       return dist[n-1][m-1];
    }
}