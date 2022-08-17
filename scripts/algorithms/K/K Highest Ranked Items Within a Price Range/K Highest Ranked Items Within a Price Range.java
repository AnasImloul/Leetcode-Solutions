class Solution {
    static class Quad
    {
        int x,y,price,dist;
        Quad(int x,int y,int price,int dist)
        {
            this.x=x;
            this.y=y;
            this.price=price;
            this.dist=dist;
        }
    }
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
        List<List<Integer>> ans=new LinkedList<>();
        PriorityQueue<Quad> pq=new PriorityQueue<>((a,b)->{
            if(a.dist!=b.dist)
                return a.dist-b.dist;
            if(a.price!=b.price)
                return a.price-b.price;
            if(a.x!=b.x)
                return a.x-b.x;
            return a.y-b.y;
        });
        bfs(grid,start[0],start[1],pricing[0],pricing[1],pq);
        while(!pq.isEmpty()&&k-->0)
        {
            Quad quad=pq.poll();
            List<Integer> temp=new LinkedList<>();
            temp.add(quad.x);
            temp.add(quad.y);
            ans.add(temp);
        }
        return ans;
    }
    void bfs(int[][] grid,int i,int j,int low,int high,PriorityQueue<Quad> pq)
    {
        Queue<int[]> queue=new LinkedList<>();
        int m=grid.length,n=grid[0].length;
        if(grid[i][j]>=low&&grid[i][j]<=high)
            pq.add(new Quad(i,j,grid[i][j],0));
        grid[i][j]=0;
        queue.add(new int[]{i,j});
        int dist=0;
        int dirs[][]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!queue.isEmpty())
        {
            ++dist;
            int size=queue.size();
            while(size-->0)
            {
                int[] p=queue.poll();
                for(int[] dir:dirs)
                {
                    int newX=dir[0]+p[0];
                    int newY=dir[1]+p[1];
                    if(newX>=0&&newY>=0&&newX<m&&newY<n&&grid[newX][newY]!=0)
                    {
                        if(grid[newX][newY]>=low&&grid[newX][newY]<=high)
                            pq.add(new Quad(newX,newY,grid[newX][newY],dist));
                        queue.add(new int[]{newX,newY});
                        grid[newX][newY]=0;
                    }
                }
            }
            
        }
    }
   

}