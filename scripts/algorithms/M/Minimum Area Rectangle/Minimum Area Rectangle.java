// Runtime: 70 ms, faster than 94.51% of Java submissions

class Solution {

    public int minAreaRect(int[][] points) {

        Map<Integer, Set<Integer>> map = new HashMap<>();

		// Group the points by x coordinates
        for (int[] point : points) {
            if (!map.containsKey(point[0])) map.put(point[0], new HashSet<>());
            map.get(point[0]).add(point[1]);
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < points.length - 1; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.length; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2) // We are looking for diagonal point, so if j is neighbour point, then continue
                    continue;

                // Note - We are calculating area first (before checking whether these points form the correct rectangle), because
                // cost of checking rectangle is very higher than calculating area. So if area less than the prev area (min), then only 
                // it makes sense to check rectangle and override min (if these points forms the correct rectangle)
                int area = Math.abs(x1 - x2) * Math.abs(y1 - y2);
                if (area < min) {
                    boolean isRectangle = map.get(x1).contains(y2) && map.get(x2).contains(y1);
                    if (isRectangle) min = area;
                }
            }
        }

        return min == Integer.MAX_VALUE ? 0 : min;
    }
}
