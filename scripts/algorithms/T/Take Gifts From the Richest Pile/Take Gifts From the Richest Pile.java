// Runtime: 6 ms (Top 79.4%) | Memory: 41.49 MB (Top 41.0%)

class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int n : gifts) pq.offer(n);
        int count = 0;
        while (count++ < k) pq.offer((int) Math.sqrt(pq.poll()));
        long sum = 0;
        while (!pq.isEmpty()) sum += pq.poll();
        return sum;
    }
}