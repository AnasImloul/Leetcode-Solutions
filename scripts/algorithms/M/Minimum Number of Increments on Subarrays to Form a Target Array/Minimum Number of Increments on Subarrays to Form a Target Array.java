// Runtime: 3 ms (Top 98.94%) | Memory: 51.4 MB (Top 94.35%)
// Imagine 3 cases
// Case 1. [3,2,1], we need 3 operations.
// Case 2. [1,2,3], we need 3 operations.
// Case 3. [3,2,1,2,3], we need 5 operations.
// What we need to add is actually the diff (cur - prev)
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
    public int minNumberOperations(int[] target) {
        int res = 0;
        int prev = 0;
        for (int cur : target) {
            if (cur > prev) {
                res += cur - prev;
            }
            prev = cur;
        }
        return res;
    }
}