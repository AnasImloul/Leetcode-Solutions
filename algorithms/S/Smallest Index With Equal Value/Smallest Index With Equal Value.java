class Solution {
    public int smallestEqual(int[] nums) {
        int index = 0;
        for (int i = 0 ; i < nums.length; i++) {
            if (index == nums[i]) {
                return i;
            }
            if (++index== 10) {
               index = 0;
            }
        }
        return -1;
    }
}
