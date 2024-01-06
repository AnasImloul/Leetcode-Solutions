// Runtime: 165 ms (Top 51.74%) | Memory: 58.10 MB (Top 98.81%)

// OJ: https://leetcode.com/contest/weekly-contest-202/problems/magnetic-force-between-two-balls/
// Author: github.com/lzl124631x
// Time: O(log(max(A)) * N + NlogN)
// Space: O(1)
class Solution {
    bool valid(vector<int> &A, int M, int m) {
        int prev = 0;
        for (int i = 1, j = 1; i < m; ++i) {
            while (j < A.size() && A[j] < A[prev] + M) ++j;
            if (j >= A.size()) return false;
            prev = j;
        }
        return true;
    }
public:
    int maxDistance(vector<int>& A, int m) {
        sort(begin(A), end(A));
        if (m == 2) return A.back() - A[0];
        int L = 1, R = A.back() - A[0];
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, M, m)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
