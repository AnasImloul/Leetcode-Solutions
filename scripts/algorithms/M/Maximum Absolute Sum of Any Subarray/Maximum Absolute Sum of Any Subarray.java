// Runtime: 3 ms (Top 94.60%) | Memory: 49.9 MB (Top 95.68%)
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int minSum = Integer.MAX_VALUE, maxSum = Integer.MIN_VALUE, currentMinSum = 0, currentMaxSum = 0;
        for(int num: nums) {
            currentMaxSum += num;
            maxSum = Math.max(maxSum, currentMaxSum);
            if (currentMaxSum < 0)
                currentMaxSum = 0;

            currentMinSum += num;
            minSum = Math.min(minSum, currentMinSum);
            if (currentMinSum > 0)
                currentMinSum = 0;
        }
        return Math.max(maxSum, -minSum);
    }
}
