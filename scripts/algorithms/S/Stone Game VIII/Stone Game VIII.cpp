class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int prefix = 0; 
        for (auto& x : stones) prefix += x; 
        
        int ans = prefix; 
        for (int i = size(stones)-2; i >= 1; --i) {
            prefix -= stones[i+1]; 
            ans = max(ans, prefix - ans); 
        }
        return ans; 
    }
};
