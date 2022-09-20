// Runtime: 14 ms (Top 32.93%) | Memory: 56.8 MB (Top 19.67%)
class Solution {
    public int majorityElement(int[] nums) {
        // Base case...
        if (nums.length == 1) {
            return nums[0];
        }
        // Sort nums array...
        Arrays.sort(nums);
        // Since the majority element appears more than n / 2 times...
        // The n/2 -th element in the sorted nums must be the majority element...
        return nums[nums.length / 2];
    }
}