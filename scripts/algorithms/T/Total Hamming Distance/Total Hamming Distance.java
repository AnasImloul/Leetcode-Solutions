// Runtime: 24 ms (Top 19.37%) | Memory: 53.8 MB (Top 78.38%)
class Solution {
    public int totalHammingDistance(int[] nums) {
        int total = 0;
        int[][] cnt = new int[2][32];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < 32; j++) {
                int idx = (nums[i] >> j) & 1;
                total += cnt[idx ^ 1][j];
                cnt[idx][j]++;
            }
        }
        return total;
    }
}