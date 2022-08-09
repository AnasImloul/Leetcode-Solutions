class Solution 
{
    //Keeping the starting position as 1
    int[][] memo = new int[255][501];
    final int MOD = (int)(1e9+7);
    public int numWays(int steps, int arrLen) 
    {
        for(int[] x: memo)
            Arrays.fill(x, -1);
        return find(1, 0, steps, arrLen);
    }
    
    int[] dx = {-1, 0, 1};
    public int find(int pos, int stepCount, int steps, int arrLen)
    {
        if(stepCount == steps)
            return pos == 1 ? 1 : 0;
        if(pos > (steps+1)/2 + 1)//Can't take more than 250 steps to right
            return 0;
        
        if(memo[pos][stepCount] != -1)
            return memo[pos][stepCount];
        
        int res = 0;
        for(int i=0;i<3;i++)
        {
            int newPos = pos + dx[i];
            if(newPos <= 0 || newPos > arrLen)//Out of bounds
                continue;
            
            res = (res + find(newPos, stepCount+1, steps, arrLen))%MOD;
        }
        return memo[pos][stepCount] = res%MOD;
    }
}
