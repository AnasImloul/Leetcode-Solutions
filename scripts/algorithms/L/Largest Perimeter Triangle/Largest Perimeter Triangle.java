// Runtime: 12 ms (Top 44.30%) | Memory: 54.1 MB (Top 55.23%)
class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);

        for(int i = nums.length - 3; i >= 0; i--) {
            if(nums[i] + nums[i + 1] > nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
}