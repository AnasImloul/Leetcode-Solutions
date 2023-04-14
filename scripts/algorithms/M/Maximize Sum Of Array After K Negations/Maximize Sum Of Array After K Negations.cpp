class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
       priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
        while(k--){
            int t=pq.top();pq.pop();
            pq.push(t*-1);
        }
    
        int n=0;
       while(!pq.empty()){
           int t=pq.top();pq.pop();
           n+=t;
       }
        return n;
    }
};