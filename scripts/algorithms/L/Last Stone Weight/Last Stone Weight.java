// Runtime: 3 ms (Top 42.30%) | Memory: 40.7 MB (Top 84.83%)
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y) -> Integer.compare(y,x));
        for (int i = 0; i < stones.length; i++) {
            pq.add(stones[i]);
        }
        while (pq.size() > 1) {
            int r1 = pq.poll();
            int r2 = pq.poll();
            if (r1 != r2) pq.add(r1 - r2);
        }
        return (pq.isEmpty()) ? 0 : pq.poll();
    }
}