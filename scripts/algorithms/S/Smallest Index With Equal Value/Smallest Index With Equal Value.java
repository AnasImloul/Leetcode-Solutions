// Runtime: 1 ms (Top 100.00%) | Memory: 42.3 MB (Top 94.74%)
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