class Solution {
    
    int[][] rects;
    TreeMap<Integer, Integer> weightedRectIndex = new TreeMap<>();
    int nPoints = 0;
    
    Random rng = new Random();

    public Solution(int[][] rects) {
        this.rects = rects;
        int index = 0;
        for (int[] rect : rects) {
		    // inserts cumulative weight key pointing to rectangle index
            weightedRectIndex.put(nPoints, index++);
            nPoints += width(rect) * height(rect);
        }
    }
    
    public int[] pick() {
	    // generates random point within total weight
        int point = rng.nextInt(nPoints);
		// finds appropriate rectangle
        var entry = weightedRectIndex.floorEntry(point);
		// find point within the current rectangle
        int rectPoint = point - entry.getKey();
        int[] rect = rects[entry.getValue()];
        return new int[]{
            rect[0] + rectPoint % width(rect), 
            rect[1] + rectPoint / width(rect)};
    }
    
    private int width(int[] rect) {
        return rect[2] - rect[0] + 1;
    }
    
    private int height(int[] rect) {
        return rect[3] - rect[1] + 1;
    }
}
