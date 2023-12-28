// Runtime: 7 ms (Top 34.2%) | Memory: 44.70 MB (Top 93.49%)

class Solution {
    public int maxSum(int[][] g) {
        
        int res=0, m=g.length, n=g[0].length,sum=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                sum=g[i-1][j-1]+g[i-1][j]+g[i-1][j+1]+g[i][j]+g[i+1][j-1]+g[i+1][j]+g[i+1][j+1];
                
            res=Math.max(res,sum);
            }
        }
        return res;
    }
}
