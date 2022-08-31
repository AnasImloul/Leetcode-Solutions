// Runtime: 250 ms (Top 27.92%) | Memory: 125.9 MB (Top 80.67%)
class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        //sort intervals
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
        //add [index,query]
        int[][] q = new int[queries.length][2];
        for (int i=0;i<queries.length;i++){
            q[i][0] = i;
            q[i][1] = queries[i];
        }
        //sort the queries by query val
        Arrays.sort(q, (a,b) -> a[1]-b[1]);
        //store the minimum intervals in the priority queue, min heap
        Queue<int[]> pq = new PriorityQueue<>((a,b) -> (a[1]-a[0])-(b[1]-b[0]));
        int[] result = new int[queries.length];
        int j = 0;
        for (int i=0;i<q.length;i++){
            int index = q[i][0];
            int val = q[i][1];
            // if start is less than query val, then add to pq
            while (j < intervals.length && intervals[j][0] <= val) pq.offer(intervals[j++]);
            //anything which has the end lesser than the val then remove it
            while (!pq.isEmpty() && pq.peek()[1] < val) pq.poll();
            //add difference to the result
            result[index]= pq.isEmpty() ? -1 : pq.peek()[1] - pq.peek()[0] + 1;
        }
    return result;
    }
}