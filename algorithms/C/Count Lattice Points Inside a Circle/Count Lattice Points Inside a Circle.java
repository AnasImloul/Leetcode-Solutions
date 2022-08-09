class Solution {
    public int countLatticePoints(int[][] circles) {
        Set<String> answer = new HashSet<String>();
        
        for (int[] c : circles) {
            int x = c[0], y = c[1], r = c[2];
            
            // traversing over all the points that lie inside the smallest square capable of containing the whole circle
            for (int xx = x - r; xx <= x + r; xx++)
                for (int yy = y - r; yy <= y + r; yy++)
                    if ((r * r) >= ((x - xx) * (x - xx)) + ((y - yy) * (y - yy)))
                        answer.add(xx + ":" + yy);
        }
        
        return answer.size();
    }
}
