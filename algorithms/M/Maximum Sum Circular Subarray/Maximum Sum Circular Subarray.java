class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int ans = kadane(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int kadane_sum = kadane(nums) + sum;
        if (kadane_sum == 0) {
            return ans;
        }
        return Math.max(ans, kadane_sum);
    }
    public int kadane(int[] nums) {
        int sum = 0;
        int ans = Integer.MIN_VALUE;
        for (int i : nums) {
            sum += i;
            ans = Math.max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
}
