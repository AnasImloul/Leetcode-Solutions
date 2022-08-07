class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int num : nums) xor ^= num;

        // Find which rightmost bit is set to 1
        int rightmostBit = 1;
        while ((rightmostBit & xor) == 0) rightmostBit = rightmostBit << 1;

        // Split nums array into 2 group based rightmost bit set
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if ((num & rightmostBit) != 0) num1 ^= num;
            else num2 ^= num;
        }
        return new int[]{num1, num2};
    }
}
