// Runtime: 49 ms (Top 24.43%) | Memory: 65.2 MB (Top 52.71%)
class Solution {
    HashMap<Integer, HashMap<Integer, Integer>> map = new HashMap<>();
    public int networkDelayTime(int[][] times, int n, int k) {
        for (int i = 1; i <= n; i++) {
            map.put(i, new HashMap<>());
        }
        for (int i = 0; i < times.length; i++) {
            map.get(times[i][0]).put(times[i][1], times[i][2]);
        }
        int ans = BFS(k, n);

        return ans == 1000 ? -1 : ans;
    }
    public int BFS(int k, int n) {
        LinkedList<Integer> queue = new LinkedList<>();

        int[] timeReach = new int[n + 1];
        Arrays.fill(timeReach, 1000);
        timeReach[0] = 0;

        timeReach[k] = 0;

        queue.add(k);

        while (!queue.isEmpty()) {
            int rv = queue.remove();
            for (int nbrs : map.get(rv).keySet()) {
                int t = map.get(rv).get(nbrs) + timeReach[rv];
                if (t < timeReach[nbrs]) {
                    timeReach[nbrs] = t;
                    queue.add(nbrs);
                }
            }
        }

        int time = 0;

        for (int i : timeReach) {
            time = Math.max(i, time);
        }

        return time;
    }
}