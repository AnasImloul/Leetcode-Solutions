// Runtime: 19 ms (Top 85.71%) | Memory: 53.00 MB (Top 11.43%)

class Solution {

    public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
        // We convert to array for faster int math and less clunky get(i)
        // syntax. This also gives us a single object pairs[i] to represent
        // each corresponding pair, and lets us sort our pairs easily.
        // While converting, we compute the sums of the two lists which we
        // will need later.
        final int[][] pairs = new int[nums1.size()][2];
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            final int n1 = nums1.get(i);
            final int n2 = nums2.get(i);
            sum1 += n1;
            sum2 += n2;
            pairs[i][0] = n1;
            pairs[i][1] = n2;
        }
        // Sort pairs by nums2 value, breaking tie by nums1 value. Note
        // that the tiebreaker doesn't actually matter, but I prefer a
        // complete ordering (helps predictability if debugging, etc).
        Arrays.sort(pairs, (a, b) -> {
            int diff = Integer.compare(a[1], b[1]);
            if (diff == 0) {
                diff = Integer.compare(a[0], b[0]);
            }
            return diff;
        });
        final int n = pairs.length;
        // We are going to compute how much we reduce the total with j ops
        // using any combination of the first i elements, working up to
        // computing j ops using all n elements. Generally, we cannot do
        // worse by including elements with larger nums2 values for same
        // number of ops, since we are free to ignore these elements. So,
        // we start with the sum reduction for i - 1 values and j ops as a
        // baseline, then compare that baseline with what happens if we
        // remove one op and replace it with zeroing out the (i - 1)st
        // pair. This lends itself to dynamic programming. The value
        // dp[i][j] tracks the best sum reduction for j operations used
        // among the first i elements.
        final int[][] dp = new int[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                final int withoutIthPair = dp[i - 1][j]; // baseline
                final int withIthPair = dp[i - 1][j - 1] // one fewer op
                        + (pairs[i - 1][1] * j) // reduce by j additions of num2
                        + pairs[i - 1][0];      // reduce by initial num1
                dp[i][j] = Math.max(withoutIthPair, withIthPair);
            }
        }
        // Now, we just look for the fewest number of ops t which provides
        // sufficient sum-reduction to get the total sum at or below x.
        for (int t = 0; t <= n; ++t) {
            final int sum = sum1 + (sum2 * t) - dp[n][t];
            if (sum <= x) {
                return t;
            }
        }
        // And, we didn't find any such t, so the answer is -1.
        return -1;
    }

}
