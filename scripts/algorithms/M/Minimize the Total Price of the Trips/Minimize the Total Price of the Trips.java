// Runtime: 17 ms (Top 54.0%) | Memory: 43.30 MB (Top 98.3%)

class Solution {
    public int minimumTotalPrice(int n, int[][] edges, int[] price, int[][] trips) {
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());            
        }
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }
        Map<Integer, Integer> counts = new HashMap<>();
        for (int[] trip : trips) {
            bfs(tree, trip[0], trip[1], counts);
        }
        int[] currPrice = new int[n];
        for (int i = 0; i < n; i++) {
            currPrice[i] = counts.getOrDefault(i, 0) * price[i];
        }
        int[] result = helper(tree, 0, -1, currPrice);
        return Math.min(result[0], result[1]);
    }
    private int[] helper(List<List<Integer>> tree, int curr, int parent, int[] currPrice) {
        List<Integer> neighbors = tree.get(curr);
        int whole = 0;
        int halved = 0;
        for (int nei : neighbors) {
            if (nei == parent) {
                continue;
            }
            int[] neiResult = helper(tree, nei, curr, currPrice);
            whole += neiResult[0];
            halved += Math.min(neiResult[0], neiResult[1]);
        }
        return new int[] {currPrice[curr] + halved, currPrice[curr] / 2 + whole};
    }
    private void bfs(List<List<Integer>> tree, int src, int dst, Map<Integer, Integer> counts) {
        int n = tree.size();
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[n];
        int[] parent = new int[n];
        Arrays.fill(parent, -1);
        queue.offer(src);
        visited[src] = true;
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            if (curr == dst) {
                break;
            }
            for (int nei : tree.get(curr)) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    parent[nei] = curr;
                    queue.offer(nei);
                }
            }
        }
        int curr = dst;
        while (curr != -1) {
            counts.put(curr, counts.getOrDefault(curr, 0) + 1);
            curr  = parent[curr];
        }
    }
}
