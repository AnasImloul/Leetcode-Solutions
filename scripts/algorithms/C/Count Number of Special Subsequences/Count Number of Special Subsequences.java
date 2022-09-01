// Runtime: 81 ms (Top 33.85%) | Memory: 118.7 MB (Top 84.62%)
class Solution {
    public int countSpecialSubsequences(int[] nums) {
        long z = 0; //starting and ending with zero
        long zo = 0; //starting with zero and ending with One
        long zot = 0;//starting with zero and ending Two
        int mod = 1000000007;
        for (int i : nums) {
            if (i == 0) {
                z = ((2*z) % mod + 1) % mod; //zero = 2*zero+1
            } else if (i == 1) {
                zo = ((2 * zo) % mod + z % mod) % mod; //zero = 2*zeroOne+zero
            } else {
                zot = ((2 * zot) % mod + zo % mod) % mod; //zeroOneTwo = 2*zeroOneTwo+zeroOne
            }
        }
        return (int)(zot%mod);
    }
}