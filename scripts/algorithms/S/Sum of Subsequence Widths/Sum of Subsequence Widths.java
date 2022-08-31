// Runtime: 49 ms (Top 70.11%) | Memory: 74.1 MB (Top 69.83%)
class Solution {
    public int sumSubseqWidths(int[] nums) {
        int MOD = (int)1e9 + 7;
        Arrays.sort(nums);

        long ans = 0;
        long p = 1;
        for(int i = 0; i < nums.length; i++){
            ans = (ans + p * nums[i] - p * nums[nums.length - 1 - i]) % MOD;
            p = (p * 2) % MOD;
        }
        return (int)ans;
    }
}