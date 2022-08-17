
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {

    public boolean ok(int[][] grid, int[][] dist, int wait_time) {
        int n = grid.length;
        int m = grid[0].length;

        Queue<Pair<Integer, Integer, Integer>> Q = new LinkedList<>();
        Q.add(new Pair<>(0, 0, wait_time));

        int[][] visited = new int[n][m];
        visited[0][0] = 1;

        while (!Q.isEmpty()) {
            Pair<Integer, Integer, Integer> at = Q.poll();
            int[][] moves = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (int[] to : moves) {
                int ii = at.first + to[0];
                int jj = at.second + to[1];
                if (!inBounds(ii, jj, n, m) || visited[ii][jj] == 1 || grid[ii][jj] == 2) continue;
                if (ii == n - 1 && jj == m - 1 && dist[ii][jj] >= at.third + 1) return true;
                if (dist[ii][jj] <= at.third + 1) continue;
                Q.add(new Pair<>(ii, jj, 1 + at.third));
                visited[ii][jj] = 1;
            }
        }
        return false;
    }

    public boolean inBounds(int i, int j, int n, int m) {
        return (0 <= i && i < n && 0 <= j && j < m);
    }

    public int maximumMinutes(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] dist = new int[n][m];

        for (int[] r : dist) Arrays.fill(r, Integer.MAX_VALUE);

        Queue<Pair<Integer, Integer, Integer>> Q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    Q.add(new Pair<>(i, j, 0));
                    dist[i][j] = 0;
                }
            }
        }

        while (!Q.isEmpty()) {
            Pair<Integer, Integer, Integer> at = Q.poll();
            int[][] moves = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int[] to : moves) {
                int ii = at.first + to[0];
                int jj = at.second + to[1];
                if (!inBounds(ii, jj, n, m) || grid[ii][jj] == 2 || dist[ii][jj] <= at.third + 1) continue;
                dist[ii][jj] = 1 + at.third;
                Q.add(new Pair<>(ii, jj, 1 + at.third));
            }
        }

        int left = 0;
        int right = 1_000_000_000;

        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ok(grid, dist, mid)) {
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }

        return ans;
    }

    static class Pair<T, K, L> {
        T first;
        K second;
        L third;

        public Pair(T first, K second, L third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

}
