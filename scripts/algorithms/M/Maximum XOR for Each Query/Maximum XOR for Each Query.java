class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xor = 0, n = nums.length;
        int max = (1 << maximumBit) - 1;
        int res[] = new int[n];
        
        for(int e : nums) xor ^= e;//xor all elements
        
        for(int i = 0; i < n; i++){
            res[i] = xor ^ max;// k = xor ^ max
            xor ^= nums[n - i - 1];//remove last element from xor
        }
        return res;
    }
}

Example
[0, 1, 1, 3] and maximumBit = 2 
xor of all elements = 3 and max = 4 -1 = 3(111)

when i = 0 => res[i] = 3 ^ 3 = 0 and xor = 3 ^ 3 = 0
when i = 1 => res[i] = 0 ^ 3 = 3 and xor = 0 ^ 1 = 1
when i = 2 => res[i] = 1 ^ 3 = 2 and xor = 1 ^ 1 = 0
when i = 3 => res[i] = 0 ^ 3 = 3 and xor = 0 ^ 0 = 0
