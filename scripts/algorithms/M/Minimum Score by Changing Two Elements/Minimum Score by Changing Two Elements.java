// Runtime: 15 ms (Top 71.6%) | Memory: 55.60 MB (Top 54.32%)

class Solution
{
    public int minimizeSum(int[] nums)
    {
        Arrays.sort(nums);
        int n = nums.length;
        return Math.min(Math.min(nums[n-1]-nums[2] , nums[n-3]-nums[0]), nums[n-2] - nums[1]);
    }
}
