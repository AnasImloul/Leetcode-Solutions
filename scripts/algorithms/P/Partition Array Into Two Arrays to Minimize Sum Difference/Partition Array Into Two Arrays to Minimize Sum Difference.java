// Runtime: 893 ms (Top 61.90%) | Memory: 51.3 MB (Top 87.91%)
class Solution {
    public int minimumDifference(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        TreeSet<Integer>[] sets = new TreeSet[n/2+1];
        for (int i = 0; i < (1 << (n / 2)); ++i) {
            int curSum = 0;
            int m = 0;
            for (int j = 0; j < n / 2; ++j) {
                if ((i & (1<<j)) != 0) {
                    curSum += nums[j];
                    m ++;
                }
            }
            if (sets[m] == null)
                sets[m] = new TreeSet<Integer>();
            sets[m].add(curSum);
        }

        int res = Integer.MAX_VALUE / 3;
        for (int i = 0; i < (1 << (n / 2)); ++i) {
            int curSum = 0;
            int m = 0;
            for (int j = 0; j < n / 2; ++j) {
                if ((i & (1<<j)) != 0) {
                    curSum += nums[n/2 + j];
                    m ++;
                }
            }
            int target = (sum - 2 * curSum) / 2;

            Integer left = sets[n/2-m].floor(target), right = sets[n/2-m].ceiling(target);
            if (left != null) {
                res = Math.min(res, Math.abs(sum - 2 * (curSum + left.intValue())));
            }

            if (right != null) {
                res = Math.min(res, Math.abs(sum - 2 * (curSum + right.intValue())));
            }

            if (res == 0)
                return 0;

        }

        return res;
    }
}
// Time Complexity: O(2^(n/2) * n/2 * n/2)