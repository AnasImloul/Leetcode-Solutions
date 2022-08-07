class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {

        Set<Integer> distances = new HashSet<>();
        distances.add(distance(p1, p2));
        distances.add(distance(p1, p3));
        distances.add(distance(p1, p4));

        distances.add(distance(p2, p3));
        distances.add(distance(p2, p4));

        distances.add(distance(p3, p4));

		// there should be only 2 unique distances (between neighbour points and apposite points)
        return !distances.contains(0) && distances.size() == 2;
    }

    private int distance(int[] p1, int[] p2) {

        // distance = (x1 - x2) ^ 2 + (y1 - y2) ^ 2;
        return ((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
}
