// Runtime: 13 ms (Top 94.44%) | Memory: 56.90 MB (Top 19.44%)

class Solution {
    public int sumOfPower(int[] nums) {
        long res = 0, s = 0, base = 1000000007;
        Arrays.sort(nums);
        for (int x: nums) {
            res = (res + (s + x) * x % base * x % base) % base;
            s = (s * 2 + x) % base;
        }
        return (int)res;
    }
}
