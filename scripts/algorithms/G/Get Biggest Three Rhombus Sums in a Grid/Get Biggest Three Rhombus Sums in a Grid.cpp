// Runtime: 644 ms (Top 13.79%) | Memory: 58.3 MB (Top 46.90%)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        set<int> s;

        // 1x1, 3x3, 5x5
        for (int len = 1; len <= min(m, n); len += 2) {
            for (int i = 0; i + len <= n; i ++) {
                for (int j = 0; j + len <= m; j ++) {
                    int d = len / 2;
                    if (d == 0) { s.insert(grid[i][j]); }
                    else {
                        int x = i, y = j + d;
                        long long sum = 0;
                        for (int k = 0; k < d; k ++) sum += grid[x++][y++];
                        for (int k = 0; k < d; k ++) sum += grid[x++][y--];
                        for (int k = 0; k < d; k ++) sum += grid[x--][y--];
                        for (int k = 0; k < d; k ++) sum += grid[x--][y++];
                        s.insert(sum);
                    }
                }
            }
        }

        if (s.size() < 3)
            return vector<int>(s.rbegin(), s.rend());

        return vector<int>(s.rbegin(), next(s.rbegin(), 3));
    }
};