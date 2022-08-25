// Runtime: 6 ms (Top 89.13%) | Memory: 97.8 MB (Top 84.45%)
class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (m > 6 * n || n > 6 * m) return -1;

        int sum1 = 0, sum2 = 0;
        for (int i : nums1) sum1 += i;
        for (int i : nums2) sum2 += i;

        int diff = sum1 - sum2;
        if (diff == 0) return 0;

        return (diff > 0 ? helper(nums1, nums2, diff)
                         : helper(nums2, nums1, -diff));
    }

    private int helper(int[] nums1, int[] nums2, int diff) {
        // count[i] : frequency of numbers that can reduce the diff by i
        int[] count = new int[6];
        for (int num : nums1) count[num - 1]++;
        for (int num : nums2) count[6 - num]++;

        int res = 0;
        for (int i = 5; i > 0; i--) {
            int c = Math.min(count[i], diff / i + (diff % i == 0 ? 0 : 1));

            res += c;
            diff -= c * i;

            if (diff <= 0) break;
        }
        return res;
    }
}