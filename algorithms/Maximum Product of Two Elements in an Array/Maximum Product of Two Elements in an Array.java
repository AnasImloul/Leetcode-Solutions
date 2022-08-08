class Solution {
    public int maxProduct(int[] nums) {
        int max = Integer.MIN_VALUE;
        int maxi = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                maxi = i;
            }
        }
        nums[maxi] = Integer.MIN_VALUE;
        int nextmax = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > nextmax) nextmax = nums[i];
        }
        return max*nextmax-max-nextmax+1;
    }
}
