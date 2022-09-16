// Runtime: 319 ms (Top 23.25%) | Memory: 57.2 MB (Top 92.90%)
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);
        int x = q.front();
        while(x < t-3000){
            q.pop(); x = q.front();
        }
        return q.size();
    }
};