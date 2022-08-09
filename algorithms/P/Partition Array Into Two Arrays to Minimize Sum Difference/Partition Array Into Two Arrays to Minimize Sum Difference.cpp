class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2; 
        vector<int> left(nums.begin(), nums.begin()+n), right(nums.begin()+n, nums.begin()+2*n); 
        
        vector<vector<int>> vals(n+1); 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? left[i] : -left[i]; 
            vals[key].push_back(diff); 
        }
        
        for (auto& v : vals) sort(v.begin(), v.end()); 
        
        int ans = INT_MAX; 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = n - __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? right[i] : -right[i]; 
            auto it = lower_bound(vals[key].begin(), vals[key].end(), -diff); 
            if (it != vals[key].begin()) ans = min(ans, abs(diff + *prev(it))); 
            if (it != vals[key].end()) ans = min(ans, abs(diff + *it)); 
        }
        return ans; 
    }
};
