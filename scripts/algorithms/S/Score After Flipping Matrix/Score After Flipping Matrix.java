// Runtime: 4 ms (Top 17.33%) | Memory: 42.9 MB (Top 9.03%)
class Solution {
    public int matrixScore(int[][] grid) {
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for(int i=0;i<grid.length;i++)
        {
            boolean flip=false;
            if(grid[i][0]==0)
            {
                grid[i][0]^=1;
                flip=true;
            }
            if(flip)
            {
             for(int j=1;j<grid[0].length;j++)
            {
                grid[i][j]^=1;
            }
            }
        }
        for(int i=1;i<grid[0].length;i++)
        {
            int zero=0;
            int one=0;
            for(int j=0;j<grid.length;j++)
            {
                if(grid[j][i]==0)
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            if(zero>one)
            {
                arr.add(i);
            }
        }
        for(int i:arr)
        {
            for(int j=0;j<grid.length;j++)
            {
                grid[j][i]^=1;
            }
        }
        int sum=0;
        for(int i=0;i<grid.length;i++)
        {
            String num="";
            for(int j=0;j<grid[0].length;j++)
            {
                num+=String.valueOf(grid[i][j]);
            }
            sum+=Integer.valueOf(num,2);
        }
        return sum;
    }
}