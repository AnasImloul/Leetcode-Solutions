// Runtime: 1 ms (Top 99.90%) | Memory: 44.3 MB (Top 29.92%)
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int[] dp = new int[1000];
        for(int i:nums1){
            dp[i]++;
        }
        int[] ans = new int[1000];

        //declaring ptr to track ans array index
        int ptr = 0;
        for(int i:nums2){
            if(dp[i] != 0){
                dp[i] = 0;
                ans[ptr] = i;
                ptr++;
            }
        }
        return Arrays.copyOfRange(ans, 0, ptr);
    }
}