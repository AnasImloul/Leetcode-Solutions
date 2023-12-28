// Runtime: 94 ms (Top 8.91%) | Memory: 32.60 MB (Top 77.65%)

// OJ: https://leetcode.com/contest/weekly-contest-286/problems/find-the-difference-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(A + B)
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa(begin(A), end(A)), sb(begin(B), end(B));
        vector<vector<int>> ans(2);
        for (int n : sa) {
            if (sb.count(n) == 0) ans[0].push_back(n);
        }
        for (int n : sb) {
            if (sa.count(n) == 0) ans[1].push_back(n);
        }
        return ans;
    }
};
