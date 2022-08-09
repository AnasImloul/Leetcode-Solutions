class Solution {
	public int numMagicSquaresInside(int[][] grid) {
		int n=grid.length,m=grid[0].length,count=0;
		for(int i=0;i<n-2;i++)
		{
			for(int j=0;j<m-2;j++)
			{
				if(sum(i,j,grid))
					count++;
			}
		}
		return count;
	}
	public boolean sum(int x,int y,int[][] grid)
	{
		int sum=grid[x][y]+grid[x][y+1]+grid[x][y+2],sum1=0,sum2=0;
		int []count=new int[10];
		for(int i=0;i<3;i++)
		{
			sum1=0;
			sum2=0;   
			for(int j=0;j<3;j++)
			{
				sum1+=grid[x+i][y+j];
				sum2+=grid[x+j][y+i];
				if(grid[x+i][y+j]<1 ||grid[x+i][y+j]>9 ||count[grid[x+i][y+j]]!=0)
					return false;
				count[grid[x+i][y+j]]=1;

			}
			if(sum1!=sum || sum!=sum2 || sum1!=sum2)
				return false;
		}
		sum1=grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
		sum2=grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y];
		if(sum1!=sum2 || sum1!=sum)
			return false;
		return true;
	}
