// Runtime: 591 ms (Top 15.83%) | Memory: 299.90 MB (Top 26.62%)

int MX = 2e5 + 2;
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int i, l, r, ans = 0;
        startPos++; // incremented positions by one to make calculations easier.
        vector<int> prefix_sum(MX);
        for(auto &it: fruits) prefix_sum[it[0] + 1] = it[1];
        for(i = 1; i < MX; i++) prefix_sum[i] += prefix_sum[i - 1];
        
        for(r = startPos; r < MX && r <= startPos + k; r++){
            l = min(startPos, startPos - (k - 2 * (r - startPos)));
            l = max(1, l);
            ans = max(ans, prefix_sum[r] - prefix_sum[l - 1]);
        }
        
        for(l = startPos; l > 0 && l >= startPos - k; l--){
            r = max(startPos, startPos + (k - 2 * (startPos - l)));
            r = min(MX - 1, r);
            ans = max(ans, prefix_sum[r] - prefix_sum[l - 1]);
        }
        return ans;
    }
};
