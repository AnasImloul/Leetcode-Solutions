class Solution {
    public int[] constructRectangle(int area) {
        int minDiff = Integer.MAX_VALUE;
        int[] result = new int[2];
        
        for (int w = 1; w*w <= area; w++) {
            if (area % w == 0) {
                int l = area / w;
                int diff = l - w;
                if (diff < minDiff) {
                    result[0] = l;
                    result[1] = w;
                    minDiff = diff;
                }
            }
        }
        
        return result;
    }
}
