// Runtime: 67 ms (Top 34.79%) | Memory: 60.8 MB (Top 55.99%)
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->(b[1]-a[1]));
        for(int i=0;i<profit.length;i++)
        {
            pq.add(new int[]{difficulty[i],profit[i]});
        }
        Arrays.sort(worker);
        int p=0;
        for(int i=worker.length-1;i>=0 && !pq.isEmpty();i--)
        {
            if(worker[i]>=pq.peek()[0])
                p=p+pq.peek()[1];
            else
            {
                while(!pq.isEmpty() && worker[i]<pq.peek()[0])
                    pq.poll();
                if(!pq.isEmpty())
                  p=p+pq.peek()[1];
            }
        }
        return p;
    }
}