class SeatManager {
    PriorityQueue<Integer> pq;
    int count;
    public SeatManager(int n) {
        count = 1;
        pq = new PriorityQueue();
    }
    
    public int reserve() {
        if(pq.size()==0)
            return count++;
        
        return pq.poll();
    }
    
    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}
