// Runtime: 20 ms (Top 41.6%) | Memory: 77.50 MB (Top 30.8%)

class Solution {
    public int countWays(int[][] ranges) 
    {
        final long MOD = 1000000007;
        long ans = 1, size = ranges.length;
        
        if (size == 1) return 2;
        
        Arrays.sort(ranges,(int[] o1, int[] o2) -> o1[0] - o2[0]);

        int overlap = 0, notOverlap = 0;
        int tillMax = Integer.MIN_VALUE;
        
        for (int idx = 1; idx < size; idx++)
        {
            tillMax = Math.max(tillMax , ranges[idx-1][1]);
            
            if (ranges[idx][0] <=ranges[idx-1][1] || ranges[idx][0] <= tillMax) overlap++;
            else notOverlap++;
        }
        
        if (overlap > 0) ans *= 2;
        else notOverlap++;
        
        for (int idx = 1; idx <= notOverlap; idx++) {
            ans = ((ans * 2) % (long)MOD);
        }
        
        return (int)ans;
    }
}