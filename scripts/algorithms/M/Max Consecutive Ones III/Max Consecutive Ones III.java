// Runtime: 2 ms (Top 100.00%) | Memory: 43.4 MB (Top 96.24%)

class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0;
        int j = -1;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                count++;
            }
            while (count > k) {
                j++;
                if (nums[j] == 0) {
                    count--;
                }
            }
            int len = i - j;
            if (len > ans) ans = len;
        }
        return ans;
    }
}