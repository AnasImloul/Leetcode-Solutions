class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        firstPlayer -= 1, secondPlayer -= 1; 
        
        map<int, vector<int>> memo; 
        function<vector<int>(int, int, int, int)> fn = [&](int r, int mask, int i, int j) {
            if (memo.find(mask) == memo.end()) {
                if (i >= j) return fn(r+1, mask, 0, n-1); 
                if (!(mask & (1 << i))) return fn(r, mask, i+1, j); 
                if (!(mask & (1 << j))) return fn(r, mask, i, j-1); 
                if ((i == firstPlayer && j == secondPlayer) || (i == secondPlayer && j == firstPlayer)) return vector<int>(2, r); 
                if (i == firstPlayer || i == secondPlayer) return fn(r, mask^(1<<j), i+1, j-1); 
                if (j == firstPlayer || j == secondPlayer) return fn(r, mask^(1<<i), i+1, j-1); 
                else {
                    vector<int> x = fn(r, mask^(1<<j), i+1, j-1); 
                    vector<int> y = fn(r, mask^(1<<i), i+1, j-1); 
                    memo[mask] = {min(x[0], y[0]), max(x[1], y[1])}; 
                }
            }
            return memo[mask]; 
        };
        
        return fn(1, (1<<n)-1, 0, n-1); 
    }
};
