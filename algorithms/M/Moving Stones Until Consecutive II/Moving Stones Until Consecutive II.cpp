class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(begin(stones), end(stones)); 
        int n = size(stones), ii = 0, low = INT_MAX, high = max(stones[n-2] - stones[0], stones[n-1] - stones[1]) - (n - 2); 
        
        for (int i = 0; i < n; ++i) {
            while (stones[i] - stones[ii] >= n) ++ii; 
            if (i - ii + 1 == n - 1 && stones[i] - stones[ii] == n - 2) low = min(low, 2); 
            else low = min(low, n - (i - ii + 1)); 
        }
        return {low, high}; 
    }
};
