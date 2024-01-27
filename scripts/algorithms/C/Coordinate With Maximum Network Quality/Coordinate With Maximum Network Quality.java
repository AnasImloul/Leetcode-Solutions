// Runtime: 16 ms (Top 84.85%) | Memory: 41.90 MB (Top 33.33%)

class Solution {
    public int[] bestCoordinate(int[][] towers, int radius) {
        int minX = 51, maxX = 0, minY = 51, maxY = 0, max = 0;
        int[] res = new int[2];
        for(int[] t : towers) {
            minX = Math.min(minX, t[0]);
            maxX = Math.max(maxX, t[0]);
            minY = Math.min(minY, t[1]);
            maxY = Math.max(maxY, t[1]);
        }
        for(int i = minX; i <= maxX; i++) {
            for(int j = minY; j <= maxY; j++) {
                int sum = 0;
                for(int[] t : towers) {
                    int d = (t[0] - i) *(t[0] - i) + (t[1] - j) *(t[1] - j);
                    if(d <= radius * radius) {
                        sum += t[2] /(1+ Math.sqrt(d));    
                    }
                }
                if(sum > max) {
                    max = sum;
                    res = new int[]{i,j};
                }
            }
        }
        return res;
    }
}
