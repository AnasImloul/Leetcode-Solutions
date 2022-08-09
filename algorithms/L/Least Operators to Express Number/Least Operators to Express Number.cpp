class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, int> memo; 
        
        function<int(int)> fn = [&](int val) {
            if (val < x) return min(2*val-1, 2*(x-val)); 
            if (memo.find(val) == memo.end()) {
                int k = log(val)/log(x); 
                memo[val] = k + fn(val - pow(x, k)); 
                if (pow(x, k+1) < 2*val) 
                    memo[val] = min(memo[val], k+1+fn(pow(x, k+1) - val)); 
            }
            return memo[val]; 
        }; 
        
        return fn(target); 
    }
};
