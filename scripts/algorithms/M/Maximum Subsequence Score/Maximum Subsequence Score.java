// Runtime: 70 ms (Top 82.71%) | Memory: 61.80 MB (Top 39.1%)

class Solution {
    record Pair(int a, int b) {}
    public long maxScore(int[] a, int[] b, int k) {
        int n = a.length;
        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; ++i) pairs[i] = new Pair(a[i], b[i]);
        Arrays.sort(pairs, (x, y) -> y.b - x.b);
        Queue<Integer> q = new PriorityQueue<>(k+1);
        long res = 0, sum = 0;
        for (var p : pairs) {
            q.add(p.a);
            sum += p.a;
            if (q.size() > k) sum -= q.poll();
            if (q.size() == k) res = Math.max(res, sum * p.b);
        }
        return res;
    }
}
