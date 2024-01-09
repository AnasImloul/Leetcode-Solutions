// Runtime: 48 ms (Top 81.41%) | Memory: 8.50 MB (Top 76.13%)

class Solution {
public:
    static const int mod = 1e9 + 7;
    vector<vector<int>> MOVES = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
};

    int cache[5001][10];

    int knightDialer(int n) {
        vector<int> nextNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        return knightDialer(n, nextNumbers);
    }

    int knightDialer(int remaining, vector<int>& nextNumbers) {
        if (remaining == 1)
            return nextNumbers.size();

        int count = 0;
        for (int nextNumber : nextNumbers) {
            int cur = cache[remaining][nextNumber];
            if (cur == 0) {
                cur = knightDialer(remaining - 1, MOVES[nextNumber]);
                cache[remaining][nextNumber] = cur;
            }
            count += cur;
            count %= mod;
        }
        return count;
    }
};
