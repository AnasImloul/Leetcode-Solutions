// Runtime: 3 ms (Top 81.5%) | Memory: 60.53 MB (Top 7.6%)

class Solution {
    public int longestSubarray(int[] nums) {
        int result = 0, length = 0, max = 0;
        for (int ele : nums) {
            max = Math.max(max, ele);
        }

        for (int ele : nums) {
            if (ele == max) {
                result = Math.max(result, ++length);
            } else length = 0;
        }
        return result;
    }
}