// Runtime: 4 ms (Top 96.40%) | Memory: 67 MB (Top 55.57%)
class Solution {
    public boolean find132pattern(int[] nums) {
        int min = Integer.MIN_VALUE;
        int peak = nums.length;
        for (int i = nums.length - 1; i >= 0; i--) {
            // We find a "132" pattern if nums[i] < min, so return true...
            if (nums[i] < min)
                return true;
            // If peak < nums.length & nums[i] is greater than the peak element...
            while (peak < nums.length && nums[i] > nums[peak])
                min = nums[peak++];
            // Now we have nums[i] <= nums[peak]
            // We push nums[i] to the "stack"
            peak--;
            nums[peak] = nums[i];
        }
        return false;
    }
}