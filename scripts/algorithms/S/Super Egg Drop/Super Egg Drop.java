// Runtime: 72 ms (Top 33.33%) | Memory: 54.3 MB (Top 43.02%)
class Solution {

    int [][]dp;
    public int superEggDrop(int k, int n) {
        dp=new int[k+1][n+1];

        for(int i=0;i<=k;i++){
            Arrays.fill(dp[i],-1);
        }

        return solve(k,n);

    }

    public int solve(int e, int f){
        if(f==0 || f==1){
            return f;
        }

        if(e==1){
            return f;
        }

        if(dp[e][f]!=-1){
            return dp[e][f];
        }

        int high=f;
        int low=1;
        int min=Integer.MAX_VALUE;

        while(low<=high){
            int k=low+(high-low)/2;

            int l=0;
            int r=0;

            if(dp[e-1][k-1]!=-1){
                l=dp[e-1][k-1];
            }else{
                l=solve(e-1,k-1);
            }

            if(dp[e][f-k]!=-1){
                r=dp[e][f-k];
            }else{
                r=solve(e,f-k);
            }

            if(l>r){
               high=k-1;
            }else{
               low=k+1;
            }

            int temp=Math.max(l,r)+1;
            min=Math.min(min,temp);
        }

        return dp[e][f]=min;
    }
}

//-------------------------TLE--------------------------

// class Solution {
// public int superEggDrop(int k, int n) {
// int [][]dp=new int[k+1][n+1];

// for(int i=1;i<=k;i++){
// for(int j=1;j<=n;j++){
// if(i==1){
// dp[i][j]=j;
// }else if(j==1){
// dp[i][j]=1;
// }else{
// int min=Integer.MAX_VALUE;

// for(int m=j-1,p=0;m>=0;m--,p++){
// int max=Math.max(dp[i][m],dp[i-1][p]);

// min=Math.min(min,max);
// }

// dp[i][j]=min+1;
// }
// }
// }

// return dp[k][n];
// }
// }