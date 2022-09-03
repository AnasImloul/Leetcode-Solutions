// Runtime: 730 ms (Top 38.78%) | Memory: 147.5 MB (Top 81.13%)
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