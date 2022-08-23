// Runtime: 1094 ms (Top 10.04%) | Memory: 110.7 MB (Top 25.95%)
class Solution {
    public int[] countRectangles(int[][] rectangles, int[][] points) {
        int max = Integer.MIN_VALUE;

        TreeMap<Integer, List<Integer>> rects = new TreeMap<>();
        for(int[] rect : rectangles) {
            if (!rects.containsKey(rect[1])) {
                rects.put(rect[1], new ArrayList<Integer>());
            }

            rects.get(rect[1]).add(rect[0]);
            max = Math.max(max, rect[1]);
        }

        for(int k : rects.keySet()) {
            Collections.sort(rects.get(k));
        }

        int[] ans = new int[points.length];
        for(int i = 0; i < points.length; i++) {
            if (points[i][1] > max) {
                continue;
            }

            int count = 0;

            for(int key : rects.subMap(points[i][1], max + 1).keySet()) {
                List<Integer> y = rects.get(key);

                count += binarySearch(y, points[i][0]);
            }

            ans[i] = count;
        }

        return ans;
    }

    private int binarySearch(List<Integer> vals, int val) {
        int lo = 0;
        int hi = vals.size() - 1;
        int id = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (vals.get(mid) < val) {
                lo = mid + 1;
            } else {
                id = mid;
                hi = mid - 1;
            }
        }

        if (id < 0) {
            return 0;
        }

        return vals.size() - id;
    }
}