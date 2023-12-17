// Runtime: 388 ms (Top 6.05%) | Memory: 45.20 MB (Top 6.85%)

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int tar) {
        int n=matrix.length,m=matrix[0].length,i,j,k,l,dp[][] = new int[n][m],val,max=Integer.MIN_VALUE,target=tar;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                dp[i][j]=matrix[i][j];
                if(j>0) dp[i][j]+=dp[i][j-1];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i>0) dp[i][j]+=dp[i-1][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                for(k=i;k<n;k++){
                    for(l=j;l<m;l++){
                        val=dp[k][l];
                        if((i-1)>=0 && (j-1)>=0) val += dp[i-1][j-1];
                        if((i-1)>=0) val=val-dp[i-1][l];
                        if((j-1)>=0) val=val-dp[k][j-1];
                        if(val>max && val<=target) max=val;
                    }
                }
            }
        }
        return max;
    }
}
