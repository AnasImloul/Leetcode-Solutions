class KthLargest {
    PriorityQueue<Integer> queue=new PriorityQueue();
    int k=0;
    public KthLargest(int k, int[] nums) {
        this.k=k;
        for(int i:nums)
            add(i);
    }
    
    public int add(int val) {
        if(k>queue.size())
            queue.add(val);
        else
            if(val>queue.peek())
            {
                queue.poll();
                queue.add(val);
            }
        return queue.peek();
    }
}
