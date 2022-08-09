class Solution {
    
    public long interchangeableRectangles(int[][] rectangles) {
        Map <Double, Long> hash = new HashMap<>();
        
        for (int i = 0; i < rectangles.length; i++) {
            Double tmp = (double) (rectangles[i][0] / (double) rectangles[i][1]);
            
            hash.put(tmp, hash.getOrDefault(tmp, 0L) + 1);
        }
        
        long ans = 0;
        for (Map.Entry<Double,Long> entry : hash.entrySet()) {
            if (entry.getValue() > 1) {
                Long n = entry.getValue();
                ans += (n * (n - 1)) / 2;
            }
        }
        
        return ans;
    }
}
