// Runtime: 13 ms (Top 73.09%) | Memory: 11 MB (Top 58.74%)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int mn_i = m, mn_j = n;
        for(auto &i : ops)
            mn_i = min(mn_i, i[0]), mn_j = min(mn_j, i[1]);

        return mn_i * mn_j;
    }
};