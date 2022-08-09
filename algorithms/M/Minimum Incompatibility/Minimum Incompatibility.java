class Solution {
    public int minimumIncompatibility(int[] nums, int k) {
        Arrays.sort(nums);
        k=nums.length/k;
        int n = nums.length,INF=100;
        int[][] dp = new int[1<<n][n];
        for (int[] d : dp){
            Arrays.fill(d, INF);
        }
        for (int i=0;i<n;i++){
            dp[1<<i][i]=0;
        }
        for (int i = 1; i < 1<<n; i++){
            int c = Integer.bitCount(i);
            for (int j=0;j<n&&c%k==0;j++){
                for (int w=0;w<n&&(i&1<<j)>0;w++){
                    if ((i&1<<w)==0){
                        dp[i|1<<w][w]=Math.min(dp[i|1<<w][w], dp[i][j]);
                    }
                }
            }
            for (int j=0;j<n&&c%k!=0;j++){
                for (int w=j+1;w<n&&(i&1<<j)>0;w++){
                    if ((i&1<<w)==0&&nums[w]!=nums[j]){
                        dp[i|1<<w][w]=Math.min(dp[i|1<<w][w], dp[i][j]+nums[w]-nums[j]);
                    }
                }
            }
        }
        int ans = Arrays.stream(dp[(1<<n)-1]).min().getAsInt();
        return ans==INF?-1:ans;
    }
}
