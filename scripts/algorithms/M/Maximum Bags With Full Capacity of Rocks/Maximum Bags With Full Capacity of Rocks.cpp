class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int res(0), n(size(rocks));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; i++) pq.push(capacity[i] - rocks[i]);
        
        while (!pq.empty() and pq.top() <= additionalRocks) {
            
			// pq.top() returns bag with least space.
            additionalRocks -= pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};
