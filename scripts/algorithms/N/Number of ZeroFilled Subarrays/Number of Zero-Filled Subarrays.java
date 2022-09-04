// Runtime: 5 ms (Top 80.84%) | Memory: 59.7 MB (Top 94.86%)
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long len = 0;
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) ++len;
            else if (len > 0) {
                ans += (len * (len + 1)) / 2;
                len = 0;
            }
        }
        if (len > 0) ans += (len * (len + 1)) / 2;
        return ans;
    }
}