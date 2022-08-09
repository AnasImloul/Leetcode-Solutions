class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0] - a[0]);
        
        for(int i=0; i<nums.length; i++)
            pq.offer(new int[]{nums[i], i});
        
        List<int[]> l = new ArrayList<>();
        
        while(k-- != 0)
            l.add(pq.poll());
        
        Collections.sort(l, (a,b) -> a[1] - b[1]);
            
        int[] res = new int[l.size()];
        
        int index = 0;
        
        for(int[] i: l)
            res[index++] = i[0];
        
        return res;
    }
}
