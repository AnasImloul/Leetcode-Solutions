// Runtime: 1 ms (Top 97.04%) | Memory: 41.60 MB (Top 27.41%)

class Solution {
    int prefix[];
    public int mergeStones(int[] stones, int k) {
        int n=stones.length;
        if((n-1)%(k-1) != 0) return -1;
        prefix=new int[stones.length+1];
        prefix[0]=0;
        int sum=0;
        for(int i=0;i<stones.length;i++){
            sum+=stones[i];
            prefix[i+1]=sum;
        }
        int dp[][]=new int[stones.length][stones.length];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                dp[i][j]=-1;
            }
        }
        return check(prefix,k,0,stones.length-1,dp);
    }
    public int check(int[] prefix,int k,int i,int j,int dp[][]){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int min=Integer.MAX_VALUE;
        for(int t=i;t<j;t=t+k-1){
            int min1=check(prefix,k,i,t,dp)+check(prefix,k,t+1,j,dp);
            min=Math.min(min,min1);
        }
        if((j-i)%(k-1)==0){
            min+=prefix[j+1]-prefix[i];
        }
        dp[i][j]=min;
        return min;
    }
}
class Solution0 {
    public int mergeStones(int[] stones, int K) {
        int n = stones.length;
        if ((n - 1) % (K - 1) > 0) return -1;

        int[] prefix = new int[n+1];
        for (int i = 0; i <  n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        int[][] dp = new int[n][n];
        for (int m = K; m <= n; ++m)
            for (int i = 0; i + m <= n; ++i) {
                int j = i + m - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int mid = i; mid < j; mid += K - 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += prefix[j + 1] - prefix[i];
            }
        return dp[0][n - 1];
    }
}
