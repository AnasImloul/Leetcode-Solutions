// Runtime: 18 ms (Top 41.09%) | Memory: 13 MB (Top 43.64%)
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % machines.size()) return -1; // impossible

        int avg = total / machines.size(), ans = 0, prefix = 0;
        for (auto& x : machines) {
            ans = max({ans, abs(prefix), x - avg});
            prefix += x - avg;
        }
        return ans;
    }
};