class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        while(k--) {
            int mini = pq.top();
            pq.pop();
            pq.push(mini + 1);
        }
        
        long long ans = 1, mod = 1e9+7;
        
        while(!pq.empty()) {
            ans = ((ans % mod) * (pq.top() % mod)) % mod;
            pq.pop();
        }
        
        return (int)ans;
    }
};
