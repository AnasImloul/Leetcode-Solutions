// Runtime: 12 ms (Top 87.2%) | Memory: 44.42 MB (Top 46.1%)

class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        //For O(N^3) Dp sapce solution
        dp2  = new Integer[m][n][m];
        int ans=solve2(0,0,0,grid,0,m,n);
        if(ans==Integer.MIN_VALUE) return 0;
        return ans;
    }
   
    private Integer[][][] dp2;
    private int solve2(int x1, int y1, int x2, int[][] g, int cpsf, int m, int n){
        int y2 = x1+y1+-x2;
        if(x1>=m||x2>=m||y1>=n||y2>=n||g[x1][y1]==-1||g[x2][y2]==-1) return Integer.MIN_VALUE;
        if(x1==m-1&&y1==n-1) return g[x1][y1];
        //If both p1 and p2 reach (m-1,n-1)
        if(dp2[x1][y1][x2]!=null) return dp2[x1][y1][x2];
        int cherries=0;
        //If both p1 and p2 are at same position then we need to add the cherry only once.
        if(x1==x2&&y1==y2){
            cherries+=g[x1][y1];
        }
        //If p1 and p2 are at different positions then repective cherries can be added.
        else{
            cherries+=g[x1][y1]+g[x2][y2];
        }
        //4 possibilites for p1 and p2 from each point
        int dd=solve2(x1+1,y1,x2+1,g,cpsf+cherries,m,n); //both moves down
        int dr=solve2(x1+1,y1,x2,g,cpsf+cherries,m,n);   //p1 moves down and p2 moves right
        int rr=solve2(x1,y1+1,x2,g,cpsf+cherries,m,n);  //both moves right 
        int rd=solve2(x1,y1+1,x2+1,g,cpsf+cherries,m,n); //p1 moves right and p2 moves down
        
        //We take maximum of 4 possiblities
        int max=Math.max(Math.max(dd,dr), Math.max(rr,rd));
        if(max==Integer.MIN_VALUE) return dp2[x1][y1][x2]=max;
        return dp2[x1][y1][x2]=cherries+=max;
    }
}
