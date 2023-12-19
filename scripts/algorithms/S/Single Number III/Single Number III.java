// Runtime: 1 ms (Top 99.89%) | Memory: 44.50 MB (Top 39.71%)

class Solution {
    public int[] singleNumber(int[] nums) {
        if (nums == null || nums.length < 2 || nums.length % 2 != 0) {
            throw new IllegalArgumentException("Invalid Input");
        }

        int aXORb = 0;
        for (int n : nums) {
            aXORb ^= n;
        }

        int rightSetBit = aXORb & -aXORb;
        int a = 0;
        for (int n : nums) {
            if ((n & rightSetBit) != 0) {
                a ^= n;
            }
        }

        return new int[] {a, aXORb ^ a};
    }
}
