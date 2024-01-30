// Runtime: 1 ms (Top 97.73%) | Memory: 42.60 MB (Top 67.71%)

class Solution {
    public boolean isGood(int[] nums) {
        int n = nums[0];
        for(int num: nums) {
            if(num > n) {
                n = num;
            }
        }
        int[] freq_map = new int[n + 1];
        for(int num: nums) {
            freq_map[num] += 1;
        }
        if(freq_map[n] != 2) {
            return false;
        }
        for(int i = 1; i < n; i++) {
            if(freq_map[i] != 1) {
                return false;
            }
        }
        return true;
    }
}
