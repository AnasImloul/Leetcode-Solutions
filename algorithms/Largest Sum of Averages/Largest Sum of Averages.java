class Solution {
    Double dp[][][];
    int n;
    int k1;
    public double check(int b, int c,long sum,int n1,int ar[]){
        System.out.println(b+" "+c);
        if(dp[b][c][n1]!=null)
            return dp[b][c][n1];
        if(b==n){
            if(sum!=0)
            return (double)sum/(double)n1;
            else
                return 0.0;}
        if(c<k1&&sum>0)
            dp[b][c][n1]=Math.max((double)sum/(double)n1+check(b,c+1,0,0,ar),check(b+1,c,sum+(long)ar[b],n1+1,ar));
        else
            dp[b][c][n1]=check(b+1,c,sum+(long)ar[b],n1+1,ar);

        return dp[b][c][n1];
    }
    public double largestSumOfAverages(int[] nums, int k) {
        n=nums.length;
        k1=k-1;
        dp= new Double[n+1][k][n+1];
        return check(0,0,0l,0,nums);
    }
}
