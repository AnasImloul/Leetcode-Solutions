class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (auto idx : indices) {
            rows[idx[0]]++;
            cols[idx[1]]++;
        }
        int counter = 0;
        for (auto i : rows) {
            for (auto j : cols) {
                counter += (i + j) % 2 == 1 ? 1 : 0;
            }
        }
        return counter;
    }
};
