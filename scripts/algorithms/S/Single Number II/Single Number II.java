// Runtime: 12 ms (Top 11.96%) | Memory: 44.6 MB (Top 34.33%)
class Solution {
    public int singleNumber(int[] nums) {

        int[] bitCount = new int[32]; // 32 bit number

        // Count occurrence of each bits in each num
        for (int i = 0; i < bitCount.length; i++) {
            for (int num : nums) {
                if ((num & 1 << i) != 0) // If ith bit in "num" is 1
                    bitCount[i]++;
            }
        }

        // Check the bit which doesn't have count multiple of 3 (i.e. no of repeating digits in input nums arr)
        // and add it to the result.
        int result = 0;
        for (int i = 0; i < bitCount.length; i++)
            result += (bitCount[i] % 3) * (1 << i);

        return result;
    }
}