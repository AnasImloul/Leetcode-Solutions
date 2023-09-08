// Runtime: 113 ms (Top 49.3%) | Memory: 43.66 MB (Top 52.1%)

class Solution {
    public int countTriplets(int[] nums) {
        int[] count = new int[1 << 16];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                count[nums[i] & nums[j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < 1 << 16; j++) {
                if ((nums[i] & j) == 0) {
                    ans += count[j];
                }
            }
        }
        return ans;
    }
}