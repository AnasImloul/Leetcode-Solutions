// Runtime: 251 ms (Top 43.04%) | Memory: 144 MB (Top 24.17%)
class Solution {
    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        int overlap = 0;
        List<Double> list = new ArrayList<>(points.size());
        for (List<Integer> p : points) {
            if (p.get(0) == location.get(0) && p.get(1) == location.get(1)) {
                overlap++;
            } else {
                list.add(angle(p.get(1) - location.get(1),
                               p.get(0) - location.get(0)));
            }
        }
        Collections.sort(list);
        int max = 0;
        int n = list.size();
        int i2 = 0;
        // list.get(i1) is first angle leg
        // list.get(i2) is second angle leg
        for (int i1 = 0; i1 < n; i1++) {
            // let's grow i1-i2 angle as much as possible
            // edge case example: angle = 30, i1 = 350 degrees, i2 = 10 degrees
            // edge case handling: allow i2 to circle around and calculate second leg as (360 + list.get(i2 % n))
            // then i1 = 350, i2 = 370, delta = 20 degrees < 30 degrees
            while ((i2 < n && list.get(i2) - list.get(i1) <= angle) ||
                   (i2 >= n && 360 + list.get(i2 % n) - list.get(i1) <= angle)) {
                i2++;
            }
            // after i2 went as far as possible away from i1 under allowed limit - check if a new maximum found
            max = Math.max(max, i2-i1);
        }
        return max + overlap;
    }

    private double angle(int dy, int dx) {
        double a = Math.toDegrees(Math.atan2(dy, dx));
        return (a < 0 ? a + 360 : a);
    }
}