// Runtime: 301 ms (Top 63.32%) | Memory: 101.4 MB (Top 52.55%)
class Solution {
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        List<int[]>[] adj = new List[n];
        for (int i = 0; i < n; ++i) adj[i] = new LinkedList();
        for (int[] e : edges) {
            int i = e[0], j = e[1], t = e[2];
            adj[i].add(new int[]{j, t});
            adj[j].add(new int[]{i, t});
        }
        int[] res = new int[1];
        int[] seen = new int[n];
        seen[0]++;
        dfs(adj, 0, values, maxTime, seen, res, values[0]);
        return res[0];
    }
    private void dfs(List<int[]>[] adj, int src, int[] values, int maxTime, int[] seen, int[] res, int sum) {
        if (0 == src) {
            res[0] = Math.max(res[0], sum);
        }
        if (0 > maxTime) return;
        for (int[] data : adj[src]) {
            int dst = data[0], t = data[1];
            if (0 > maxTime - t) continue;
            seen[dst]++;
            dfs(adj, dst, values, maxTime - t, seen, res, sum + (1 == seen[dst] ? values[dst] : 0));
            seen[dst]--;
        }
    }
}