class Solution {
    public int smallestRangeI(int[] nums, int k) {
        if (nums.length == 1)
            return 0;
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for (int num: nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        int diff = max - min;
        
        return Math.max(0, diff - 2*k);
    }
}
