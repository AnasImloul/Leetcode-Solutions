// Runtime: 116 ms (Top 36.54%) | Memory: 59.20 MB (Top 50.0%)

class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        // Create a TreeMap to store the segment start and end points as keys
        // and the accumulated color values as values
        TreeMap<Long, Long> tm = new TreeMap<>();
        
        // Process each segment
        for (int[] seg : segments) {
            // Increment the color value at the segment start point
            tm.put((long) seg[0], tm.getOrDefault((long) seg[0], 0L) + (long) seg[2]);
            
            // Decrement the color value at the segment end point
            tm.put((long) seg[1], tm.getOrDefault((long) seg[1], 0L) - (long) seg[2]);
        }
        
        // Create a list to store the non-overlapping segments of mixed colors
        List<List<Long>> ans = new ArrayList<>();
        
        // Variables to keep track of accumulated color value and segment state
        long acc = 0L;
        boolean st = true;
        List<Long> currentSegment = null;
        
        // Traverse the TreeMap entries
        for (var entry : tm.entrySet()) {
            // Update the accumulated color value
            acc += entry.getValue();
            
            // If the previous segment was not starting, update its end point
            if (!st) {
                currentSegment.set(1, entry.getKey());
                st = !st;
            }
            
            // If the current segment is starting and has a positive accumulated color value,
            // create a new segment and add it to the answer list
            if (st && acc > 0) {
                currentSegment = new ArrayList<>();
                currentSegment.add(entry.getKey());
                currentSegment.add(-1L);
                currentSegment.add(acc);
                ans.add(currentSegment);
                st = !st;
            }
        }
        
        return ans;
    }
}

