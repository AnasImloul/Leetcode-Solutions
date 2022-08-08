class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        const int m = 1e9 + 7;
        vector<vector<int>> pairs(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++) pairs[i] = {efficiency[i], speed[i]};
        sort(pairs.rbegin(), pairs.rend());
        for(int i = 0; i < n; i++){
            sum += pairs[i][1];
            pq.push(pairs[i][1]);
            ans = max(ans,sum * pairs[i][0]);
            if(pq.size() >= k){
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans%(m);
    }
}; 
