// Runtime: 699 ms (Top 7.8%) | Memory: 55.45 MB (Top 34.4%)


class Solution { //Using Priority Queue
    public int maximumRobots(int[] ct, int[] rc, long budget) {// T.C: 0(N) A.S:0()
     PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int n = rc.length;
        int res = Integer.MIN_VALUE;
        long cost = 0;
        for (int i = 0, j = 0; i < n; i++) {
            cost += rc[i];
            pq.add(ct[i]);
            while (!pq.isEmpty() && (pq.peek() + pq.size() * cost > budget)) {
                pq.remove(ct[j]);
                cost -= rc[j];
                j++;
            }
            res = Math.max(res, pq.size());
        }
        return res;
    }
}