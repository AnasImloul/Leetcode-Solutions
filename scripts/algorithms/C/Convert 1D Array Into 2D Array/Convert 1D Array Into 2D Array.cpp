// Runtime: 251 ms (Top 39.98%) | Memory: 87.3 MB (Top 63.78%)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};

        vector<vector<int>> res;
        for (int i = 0; i < m*n; i+=n)
            res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));

        return res;
    }
};