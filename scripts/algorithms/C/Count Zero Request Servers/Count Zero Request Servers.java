// Runtime: 42 ms (Top 84.2%) | Memory: 79.20 MB (Top 85.9%)

class Solution {

    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int m = queries.length;
        int[] counts = new int[n + 1], output = new int[m];
        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<>();
        Arrays.sort(logs, Comparator.comparingInt(log -> log[1]));
        for (int i = 0; i < m; i++) {
            map.putIfAbsent(queries[i], new ArrayList<>());
            map.get(queries[i]).add(i);
        }
        int a = 0, b = 0, c = n;
        for (Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
            int t = entry.getKey();
            while (a < logs.length && logs[a][1] <= t) {
                int s = logs[a++][0];
                if (counts[s]++ == 0) c--;
            }
            while (b < a && logs[b][1] < t - x) {
                int s = logs[b++][0];
                if (--counts[s] == 0) c++;
            }
            for (int i : entry.getValue()) output[i] = c;
        }
        return output;
    }

}