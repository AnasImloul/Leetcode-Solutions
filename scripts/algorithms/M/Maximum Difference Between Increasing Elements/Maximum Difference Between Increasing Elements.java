// Runtime: 0 ms (Top 100.00%) | Memory: 41.2 MB (Top 99.17%)
class Solution {
    public int maximumDifference(int[] nums) {
        if(nums.length < 2)
            return -1;
        int result = Integer.MIN_VALUE;
        int minValue = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > minValue)
                result = Math.max(result, nums[i] - minValue);
            minValue = Math.min(minValue, nums[i]);
        }
        return result == Integer.MIN_VALUE ? -1 : result;
    }
}