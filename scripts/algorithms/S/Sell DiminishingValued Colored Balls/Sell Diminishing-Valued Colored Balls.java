// Runtime: 89 ms (Top 16.36%) | Memory: 101.4 MB (Top 5.25%)
class Solution {
    private long mod = 1000000007L;
    public int maxProfit(int[] inventory, int orders) {
        // we use pq to find the most balls
        PriorityQueue<Long> pq = new PriorityQueue<>((x, y) -> Long.compare(y, x));
        pq.offer(0L);

        // we use map to count the balls
        Map<Long, Long> map = new HashMap<>();
        map.put(0L, 0L);

        for (int j : inventory) {
            long i = (long)j;
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            }
            else {
                pq.offer(i);
                map.put(i, 1L);
            }
        }

        long res = 0;
        while (orders > 0) {
            long ball = pq.poll(), nextBall = pq.peek();
            long times = map.get(ball);
            long diff = Math.min(ball - nextBall, orders / times);
            if (diff == 0) {
                res = (res + orders * ball) % mod;
                break;
            }
            long sum = (ball * 2 + 1 - diff) * diff / 2 * times;
            res = (res + sum) % mod;
            orders -= diff * times;
            if (!map.containsKey(ball - diff)) {
                map.put(ball - diff, map.get(ball));
                pq.offer(ball - diff);
            }
            else {
                map.put(ball - diff, map.get(ball - diff) + map.get(ball));
            }
            map.remove(ball);
        }
        return (int) res;
    }
}