// Runtime: 108 ms (Top 6.05%) | Memory: 86.60 MB (Top 5.1%)

class Solution {
    private Integer[][] dp;
    
    public int maxNonDecreasingLength(int[] nums1, int[] nums2) {
        int n = nums1.length;
        dp = new Integer[n][3];
        return solve(0, 0, n, nums1, nums2);
    }
    
    // choice := what we chose previously = 0 for nothing, 1 for num1, 2 for num2
    private int solve(int idx, int choice, int n, int[] nums1, int[] nums2) {
        if(idx == n) return 0;
        if(dp[idx][choice] != null) return dp[idx][choice];
        int maxLen = 0;
        
        // if previously we haven't chosen a value then we can
        // either skip this value too or take this value
        if(choice == 0) maxLen = Math.max(maxLen, solve(idx + 1, 0, n, nums1, nums2));
        int prev = choice == 0 ? -1 : choice == 1 ? nums1[idx - 1] : nums2[idx - 1];
        if(nums1[idx] >= prev) {
            maxLen = Math.max(maxLen, 1 + solve(idx + 1, 1, n, nums1, nums2));
        }
        if(nums2[idx] >= prev) {
            maxLen = Math.max(maxLen, 1 + solve(idx + 1, 2, n, nums1, nums2));
        }
        return dp[idx][choice] = maxLen;
    }
}
