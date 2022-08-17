class Solution {
    Integer dp[][];
    public int minPathCost(int[][] grid, int[][] moveCost) 
    {
        dp=new Integer[grid.length][grid[0].length];
        int ans=Integer.MAX_VALUE;
       
        for(int i=0;i<grid[0].length;i++)
        {
            ans=Math.min(ans,grid[0][i]+helper(grid,moveCost,grid[0][i],1));
        }
        return ans;
    }
    public int helper(int[][] grid,int[][] moveCost,int cur,int i)
    {
        if(i==grid.length)
        {
            return 0;
        }
        int ans=Integer.MAX_VALUE;
        for(int k=0;k<grid[0].length;k++)
        {
            int a=Integer.MAX_VALUE;
            if(dp[i][k]!=null)
            {
                a=dp[i][k];
            }
            else
            {
                a=helper(grid,moveCost,grid[i][k],i+1);
                dp[i][k]=a;
            }
            ans=Math.min(grid[i][k]+moveCost[cur][k]+a,ans);
        }
        return ans;
    }
}
