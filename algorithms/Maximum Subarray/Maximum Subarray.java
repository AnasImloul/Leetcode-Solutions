class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int currmax = 0;
        int gmax = nums[0];
        for(int i=0;i<n;i++) {
            currmax+=nums[i];
            gmax=Math.max(gmax, currmax);
            currmax=Math.max(currmax, 0);
        }
        return gmax;
    }
}
