// Runtime: 2 ms (Top 19.55%) | Memory: 56.30 MB (Top 85.71%)

class Solution {
    public int getXORSum(int[] arr1, int[] arr2) {
        
        int xor1 = 0, xor2 = 0;
        
        for (int arr : arr1) {
            xor1 ^= arr;
        }
        
        for (int arr : arr2) {
            xor2 ^= arr;
        }
        
        return xor1 & xor2;
    }
}
