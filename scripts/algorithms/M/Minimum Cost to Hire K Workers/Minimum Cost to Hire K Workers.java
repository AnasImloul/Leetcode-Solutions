// Runtime: 26 ms (Top 87.91%) | Memory: 46.20 MB (Top 6.51%)

class Worker implements Comparable<Worker> {
    final int q, w;
    public Worker(int q, int w) {
        this.q = q;
        this.w = w;
    }
    @Override
    public int compareTo(Worker other) {
        return Integer.compare(w * other.q, q * other.w);
    }
}
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        Worker[] a = new Worker[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new Worker(quality[i], wage[i]);
        }
        Arrays.sort(a);
        int s = 0;
        double res = 1e15;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (Worker worker: a) {
            q.add(-worker.q);
            s += worker.q;
            if (q.size() > k) s += q.poll();
            if (q.size() == k) res = Math.min(res, (double) s * worker.w / worker.q);
        }
        return res;
    }
}
