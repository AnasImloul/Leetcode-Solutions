class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int count = 1;
        int maxCount = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                maxCount = Math.max(count, maxCount);
                count = 1;
            }
        }
        maxCount = Math.max(count, maxCount);
        return maxCount;
    }
}
