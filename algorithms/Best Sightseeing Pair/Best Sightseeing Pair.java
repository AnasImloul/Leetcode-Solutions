class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n=values.length;
        int[] dp=new int[n];
        dp[0]=values[0];
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i]=Math.max(dp[i-1],values[i]+i);
            ans=Math.max(ans,dp[i-1]+values[i]-i);
        }
        return ans;
    }
}
