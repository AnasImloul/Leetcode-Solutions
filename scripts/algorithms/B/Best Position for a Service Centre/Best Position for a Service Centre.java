class Solution {
    private static final double MIN_STEP = 0.0000001;
    private static final int[][] DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public double getMinDistSum(int[][] positions) {
        double cx = 0, cy = 0;
        int n = positions.length;
        for (int[] pos: positions) {
            cx += pos[0];
            cy += pos[1];
        }
        cx /= n; cy /= n;
        Node center = new Node(cx, cy, totalDistance(positions, cx, cy));

        double step = 50.0;
        while (step > MIN_STEP) {
            Node min = center;
            for (int[] direction: DIRECTIONS) {
                double dx = center.x + direction[0] * step, dy = center.y + direction[1] * step;
                double totalDist = totalDistance(positions, dx, dy);
                if (totalDist < center.dist) min = new Node(dx, dy, totalDist);
            }
            if (center == min) step /= 2;
            center = min;
        }

        return center.dist;
    }

    private double sq(double p) {
        return p * p;
    }

    private double dist(int[] pos, double x, double y) {
        return Math.sqrt(sq(x - pos[0]) + sq(y - pos[1]));
    }

    private double totalDistance(int[][] positions, double x, double y) {
        double dist = 0;
        for (int[] pos: positions) dist += dist(pos, x, y);
        return dist;
    }

    private static class Node {
        double x, y, dist;
        Node (double x, double y, double dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}
