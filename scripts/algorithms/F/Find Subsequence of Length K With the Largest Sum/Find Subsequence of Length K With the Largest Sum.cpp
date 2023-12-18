// Runtime: 9 ms (Top 29.13%) | Memory: 9.60 MB (Top 91.68%)

// OJ: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& A, int k) {
        vector<int> id(A.size());
        iota(begin(id), end(id), 0); // Index array 0, 1, 2, ...
        sort(begin(id), end(id), [&](int a, int b) { return A[a] > A[b]; }); // Sort the indexes in descending order of their corresponding values in `A`
        id.resize(k); // Only keep the first `k` indexes with the greatest `A` values
        sort(begin(id), end(id)); // Sort indexes in ascending order
        vector<int> ans;
        for (int i : id) ans.push_back(A[i]);
        return ans;
    }
};
