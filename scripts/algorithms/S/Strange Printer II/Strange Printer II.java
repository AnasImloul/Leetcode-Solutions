// Runtime: 85 ms (Top 41.74%) | Memory: 54.3 MB (Top 53.04%)
class Solution {
    // store each color's left, top, right, bottom
    private Set<Integer>[] graph;
    private int[] indegrees;
    private int[][] ranges;
    private boolean[] exists;
    private int m;
    private int n;
    private int maxColor = 60;
    public boolean isPrintable(int[][] targetGrid) {
        this.m = targetGrid.length;
        this.n = targetGrid[0].length;
        buildRanges(targetGrid);
        buildGraph(targetGrid);
        int count = 0;
        int totalCount = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= maxColor; i++) {
            if (exists[i]) {
                if (indegrees[i] == 0) {
                    queue.offer(i);
                }
                totalCount++;
            }
        }
        while (!queue.isEmpty()) {
            count++;
            Integer current = queue.poll();
            for (Integer neighbor: graph[current]) {
                if (--indegrees[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }
        return count == totalCount;
    }
    private void buildRanges(int[][] targetGrid) {
        this.ranges = new int[maxColor + 1][4];
        for (int i = 1; i <= maxColor; i++) {
            ranges[i][0] = ranges[i][1] = Integer.MAX_VALUE;
            ranges[i][2] = ranges[i][3] = Integer.MIN_VALUE;
        }
        exists = new boolean[maxColor + 1];
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                exists[color] = true;
                max = Math.max(max, color);
                ranges[color][0] = Math.min(ranges[color][0], j);
                ranges[color][1] = Math.min(ranges[color][1], i);
                ranges[color][2] = Math.max(ranges[color][2], j);
                ranges[color][3] = Math.max(ranges[color][3], i);
            }
        }
        maxColor = max;
    }
    // TC O(n^3) to build graph
    private void buildGraph(int[][] targetGrid) {
        graph = new Set[maxColor + 1];
        indegrees = new int[maxColor + 1];
        for (int c = 1; c <= maxColor; c++) {
            if (exists[c]) {
                graph[c] = new HashSet<>();
                for (int i = ranges[c][1]; i <= ranges[c][3]; i++) {
                    for (int j = ranges[c][0]; j <= ranges[c][2]; j++) {
                        int other = targetGrid[i][j];
                        if (other != c && !graph[c].contains(other)) {
                            graph[c].add(other);
                            indegrees[other]++;
                        }
                    }
                }
            }
        }
    }
}