// Runtime: 1 ms (Top 96.85%) | Memory: 54.60 MB (Top 93.24%)

class Solution {
    public int xorBeauty(int[] nums) {
        int xor = 0;
        for (int num : nums)
            xor ^= num;
        return xor;
    }
}
