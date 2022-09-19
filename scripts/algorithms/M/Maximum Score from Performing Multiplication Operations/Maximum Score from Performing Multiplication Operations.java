// Runtime: 360 ms (Top 22.12%) | Memory: 168.2 MB (Top 19.45%)
class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        int n = nums.length, m = multipliers.length;
        return helper(nums, multipliers, 0, 0, n-1, new Integer[m][m]);
    }

    public int helper(int[] nums, int[] multipliers, int idx, int left, int right, Integer[][] memo){
        if(idx == multipliers.length) return 0;
        if(memo[idx][left] != null) return memo[idx][left];

        int takeLeft = nums[left] * multipliers[idx] +
            helper(nums, multipliers, idx + 1, left + 1, right, memo);

        int takeRight = nums[right] * multipliers[idx] +
            helper(nums, multipliers, idx + 1, left, right - 1, memo);

        return memo[idx][left] = Math.max(takeLeft, takeRight);
    }
}