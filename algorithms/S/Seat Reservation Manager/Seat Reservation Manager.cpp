class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) pq.push(i);
    }
    
    int reserve() {
        int top = pq.top(); pq.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
