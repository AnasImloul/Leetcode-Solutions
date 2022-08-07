class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] dp = new int[1000+1];
        for(int i: nums1){
            dp[i]++;
        }
        int ptr =0;
        int ans[] = new int[1000+1];
        for(int i:nums2){
            if(dp[i]!= 0){
                ans[ptr]= i;
                ptr++;
                dp[i]--;
            }
                        
        }
        return Arrays.copyOfRange(ans,0,ptr);
    }
}
