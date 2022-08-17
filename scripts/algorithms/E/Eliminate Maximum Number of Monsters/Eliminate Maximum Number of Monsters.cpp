class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> pq;
        
        for(int i = 0; i < dist.size(); ++i)
            pq.push(ceil((double)dist[i] / speed[i] ));
        
        int t = 0;
        while(pq.size() && pq.top() > t++) pq.pop();
        return dist.size() - pq.size();
    }
};
