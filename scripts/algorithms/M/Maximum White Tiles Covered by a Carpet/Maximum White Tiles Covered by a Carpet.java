// Runtime: 45 ms (Top 71.1%) | Memory: 71.05 MB (Top 47.1%)

class Solution
{
    public int maximumWhiteTiles(int[][] tiles, int carpetLen)
    {
        Arrays.sort(tiles,(a,b)->{return a[0]-b[0];});
        int x = 0;
        int y = 0;
        long maxCount = 0;
        long count = 0;
        
        while(y < tiles.length && x <= y)
        {
            long start = tiles[x][0];
            long end = tiles[y][1];
            
            if(end-start+1 <= carpetLen) 
            {
                count += tiles[y][1] - tiles[y][0]+1;
                maxCount = Math.max(maxCount,count);
                y++;
            }
            else 
            {
                long midDist = start+carpetLen-1;
                long s = tiles[y][0];
                long e = tiles[y][1];
                if(midDist <= e && midDist >= s)  maxCount = Math.max(maxCount,count+midDist-s+1);
                count -= tiles[x][1] - tiles[x][0] + 1;
                x++;
            }
        }
        return (int)maxCount;
    }
}