class Solution {
    public boolean checkPossibility(int[] nums) {
        int modified = 0, prev = nums[0], index = 0;
        for (; index < nums.length; ++index) {
            if (nums[index] < prev) {
                if (++modified > 1) return false;
                if (index - 2 >= 0 && nums[index - 2] > nums[index]) continue;
            }
            prev = nums[index];
        }
        return true;
    }
}
