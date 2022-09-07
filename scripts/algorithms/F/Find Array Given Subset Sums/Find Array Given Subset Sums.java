// Runtime: 73 ms (Top 62.96%) | Memory: 85.2 MB (Top 70.37%)
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        Arrays.sort(sums);
        int m = sums.length;
        int[] res = new int[n], left = new int[m / 2], right = new int[m / 2];
        for (int i = 0; i < n; ++i) {
            int diff = sums[1] - sums[0], hasZero = 0, p = -1, q = -1, k = 0;
            for (int j = 0; j < m; ++j) {
                if (k <= q && right[k] == sums[j]) k++;
                else {
                    if (0 == sums[j]) hasZero = 1;
                    left[++p] = sums[j];
                    right[++q] = sums[j] + diff;
                }
            }
            if (1 == hasZero) {
                res[i] = diff;
                sums = left;
            } else {
                res[i] = -diff;
                sums = right;
            }
            m /= 2;
        }
        return res;
    }
}