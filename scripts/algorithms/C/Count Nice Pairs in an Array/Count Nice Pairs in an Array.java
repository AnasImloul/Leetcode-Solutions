// Runtime: 21 ms (Top 85.52%) | Memory: 58.10 MB (Top 25.69%)

class Solution {
    public int countNicePairs(int[] nums) {
        final int mod = 1000000007;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        Arrays.sort(nums);
        long res = 0;
        for (int i = 0; i < len - 1; i++) {
            long count = 1;
            while (i < len - 1 && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            res = (res % mod + (count * (count - 1)) / 2) % mod;
        }

        return (int) (res % mod);
    }
    private int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
}
