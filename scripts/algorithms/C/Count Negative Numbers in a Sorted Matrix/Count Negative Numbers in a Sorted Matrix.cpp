// Runtime: 29 ms (Top 41.34%) | Memory: 11 MB (Top 7.78%)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; for (auto hehe : grid) for (int i : hehe) if (i < 0) ans++; return ans;
    }
};