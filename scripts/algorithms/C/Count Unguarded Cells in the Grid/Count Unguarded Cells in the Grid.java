class Solution
{
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls)
    {
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        char[][] grid= new char[m][n];
        int count = m*n - guards.length - walls.length;
        for(int[] wall : walls)
        {
            int x = wall[0], y = wall[1];
            grid[x][y] = 'W';
        }
        for(int[] guard : guards)
        {
            int x = guard[0], y = guard[1];
            grid[x][y] = 'G';
        }
        for(int[] point : guards)
        {
            for(int dir[] : dirs)
            {
                int x = point[0] + dir[0];
                int y = point[1] + dir[1];
                while(!(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'G' || grid[x][y] == 'W'))
                {
                    if(grid[x][y] != 'P')
                        count--;
                    grid[x][y] = 'P';
                    x += dir[0];
                    y += dir[1];
                }
            }
        }
        return count;
    }
}
