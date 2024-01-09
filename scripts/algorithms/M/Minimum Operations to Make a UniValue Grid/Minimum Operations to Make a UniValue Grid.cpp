// Runtime: 194 ms (Top 92.63%) | Memory: 83.30 MB (Top 85.26%)

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size(), mod = grid[0][0] % x;
        vector<int> v;
        for (auto &row : grid)
            for (int cell : row) {
                if (cell % x != mod)
				{
                    return -1;
				}
                v.push_back(cell / x);
            }
        sort(v.begin(), v.end());
        int mid = n * m / 2;
        int result= 0;
        for (int vi : v)
		{
            result += abs(vi - v[mid]);
		}
        return result;
    }
};
