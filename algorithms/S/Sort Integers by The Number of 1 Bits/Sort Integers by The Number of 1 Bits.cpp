class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = size(arr);
        priority_queue<pair<int, int>> pq;
        
        for(auto &x : arr) {
            int count = 0;
            int a = x;
            while(a) {
                count += a & 1;
                a >>= 1;
            }
            pq.push({count, x});
        }
        n = n - 1;
        while(!pq.empty()) {
            arr[n--] = pq.top().second;
            pq.pop();
        }
        
        return arr;
    }
};
