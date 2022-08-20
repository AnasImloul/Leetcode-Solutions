// Runtime: 737 ms (Top 44.40%) | Memory: 107.9 MB (Top 75.00%)

array<int, 2> operator+(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] + r[0], l[1] + r[1] }; }
array<int, 2> operator-(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] - r[0], l[1] - r[1] }; }
int pairs(const array<int, 2> &p) { return min(p[0], p[1]); }

class Solution {
public:
int factors(int i, int f) {
    return i % f ? 0 : 1 + factors(i / f, f);
}
int maxTrailingZeros(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m + 1, vector<array<int, 2>>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            array<int, 2> f25 = { factors(grid[i][j], 2), factors(grid[i][j], 5) };
            v[i + 1][j] = v[i][j] + f25;
            h[i][j + 1] = h[i][j] + f25;
        }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            auto v1 = v[i + 1][j], v2 = v[m][j] - v[i][j];
            auto h1 = h[i][j], h2 = h[i][n] - h[i][j + 1];
            res = max({res, pairs(v1 + h1), pairs(v1 + h2), pairs(v2 + h1), pairs(v2 + h2)});
        }
    return res;
}
};