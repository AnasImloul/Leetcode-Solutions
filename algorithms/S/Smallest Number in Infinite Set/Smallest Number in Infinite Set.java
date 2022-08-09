class SmallestInfiniteSet {
    private PriorityQueue<Integer> q;
    private int index;
    public SmallestInfiniteSet() {
        q = new PriorityQueue<Integer>();
        index = 1;
    }
    
    public int popSmallest() {
        if (q.size()>0){
            return q.poll();
        }
        return index++;
    }
    
    private boolean is_in_q(int num){
        for(int i : q){
            if (i == num){
                return true;
            }
        }
        return false;
    }
    
    public void addBack(int num) {
        if( num < index && !is_in_q(num)){
            q.add(num);
        }
    }
}
